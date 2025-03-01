#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ff.h"

uint32_t u32_from_u8_buffer_big_endian(uint8_t* buf) {
    return (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
}

uint32_t get_syncsafe_value(uint32_t i) {
    uint32_t res = (i & 0x7F);

    res |= ((i & 0x7F00) >> 1);
    res |= ((i & 0x7F0000) >> 2);
    res |= ((i & 0x7F000000) >> 3);

    return res;
}

bool read_id3_text_frame(FIL* file, uint8_t* buf, uint32_t buf_len, uint32_t frame_size)
{
    UINT bytes_read;

    /* Check that encoding is one we can parse */
    if((f_read(file, buf, 1, &bytes_read) != FR_OK) || (bytes_read != 1))
    {
        return false;
    }
    else if((buf[0] != 0x00) && (buf[0] != 0x03))
    {
        /* Not ASCII or UTF-8, fail */
        return false;
    }

    UINT read_len = ((frame_size - 1) <= buf_len) ? (frame_size - 1) : buf_len;

    if((f_read(file, buf, read_len, &bytes_read) != FR_OK) || (bytes_read != read_len))
    {
        return false;
    }
    else
    {
        buf[buf_len - 1] = '\0'; /* Just in case */
    }

    return true;
}

bool parse_id3_data(uint8_t* path, uint8_t* title, uint32_t title_len,
        uint8_t* album, uint32_t album_len, uint8_t* artist, uint32_t artist_len)
{
    FIL file;

    uint8_t buf[64];
    UINT bytes_read;
    uint8_t flags;

    if(f_open(&file, (char*)path, FA_READ) != FR_OK)
    {
        return false;
    }
    else
    {
        if((f_read(&file, buf, 10, &bytes_read) != FR_OK) || (bytes_read != 10))
        {
            return false;
        }
        else
        {
            if(strncmp((char*)buf, "ID3", 3) == 0)
            {
                flags = buf[5];

                uint32_t raw_size = u32_from_u8_buffer_big_endian(&(buf[6]));
                uint32_t id3_size = get_syncsafe_value(raw_size);

                uint32_t ext_header_len;

                /* Check for extended header */
                if(flags & 0x40)
                {
                    if((f_read(&file, buf, 4, &bytes_read) != FR_OK) || (bytes_read != 4))
                    {
                        ext_header_len = get_syncsafe_value(u32_from_u8_buffer_big_endian(buf)) - 4;
                    }
                    else
                    {
                        /* Extended header indicated, but missing */
                        return false;
                    }
                }
                else
                {
                    ext_header_len = 0;
                }

                f_lseek(&file, f_tell(&file) + ext_header_len);

                while((f_tell(&file) < id3_size) && (!f_eof(&file)))
                {
                    /* Get next frame header */
                    if((f_read(&file, buf, 10, &bytes_read) != FR_OK) || (bytes_read != 10))
                    {
                        return false;
                    }
                    else
                    {
                        uint32_t frame_size = get_syncsafe_value(u32_from_u8_buffer_big_endian(&(buf[4])));

                        /* Title */
                        if(strncmp((char*)buf, "TIT2", 4) == 0)
                        {
                            if(!read_id3_text_frame(&file, title, title_len, frame_size))
                            {
                                return false;
                            }
                        }

                        /* Album */
                        else if(strncmp((char*)buf, "TALB2", 4) == 0)
                        {
                            if(!read_id3_text_frame(&file, album, album_len, frame_size))
                            {
                                return false;
                            }
                        }

                        /* Artist */
                        else if(strncmp((char*)buf, "TPE1", 4) == 0)
                        {
                            if(!read_id3_text_frame(&file, artist, artist_len, frame_size))
                            {
                                return false;
                            }
                        }

                        else
                        {
                            f_lseek(&file, f_tell(&file) + frame_size);
                        }
                    }
                }
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}
