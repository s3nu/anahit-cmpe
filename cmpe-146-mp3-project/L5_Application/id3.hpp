#ifndef __ID3_H
#define __ID3_H

#include <stdint.h>

bool parse_id3_data(uint8_t* path, uint8_t* title, uint32_t title_len,
        uint8_t* album, uint32_t album_len, uint8_t* artist, uint32_t artist_len);

#endif
