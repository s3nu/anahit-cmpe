//I2c LAB
class lab5: public scheduler_task {
public:
    lab5() :
        scheduler_task("lab5", 2000, PRIORITY_LOW) {
        printf("lab5 task started");
    }

    bool init(void) {
        i2c.slave(slaveadder, buffer, sizeof(buffer));

        return true;
    }

    bool run(void *p) {
        //          I2C2& i2c = I2C2::getInstance(); // Get I2C driver instance
        //          const uint8_t slaveadder = 0x60;  // Pick any address other than the used used at i2c2.hpp
        //          uint8_t buffer[256] = { 0 };     // Our slave read/write buffer
        uint8_t prev = buffer[0];
        while (1) {
            if (prev != buffer[0]) {
                prev = buffer[0];
                u0_dbg_printf("buffer[0] changed to %#x\n", buffer[0]);
            }
        }
        return true;
    }
private:
    I2C2& i2c = I2C2::getInstance(); // Get I2C driver instance
    const uint8_t slaveadder = 0x66; // Pick any address other than the used used at i2c2.hpp
    uint8_t buffer[256] = { 0 };
};

int main(void) {
        I2C2& i2c = I2C2::getInstance(); // Get I2C driver instance
        const uint8_t slaveAddr = 0xC0;  // Pick any address other than an existing one at i2c2.hpp
        volatile uint8_t buffer[256] = { 0 }; // Our slave read/write buffer (This is the memory your other master board will read/write)

         I2C is already initialized before main(), so you will have to add initSlave() to i2c base class for your slave driver
        i2c.init_slave(slaveAddr, &buffer[0], sizeof(buffer));

         I2C interrupt will (should) modify our buffer.
         So just monitor our buffer, and print and/or light up LEDs
         ie: If buffer[0] == 0, then LED ON, else LED OFF
            scheduler_add_task(new lab5());
            uint8_t prev = buffer[0];
            while(1)
            {
                if (prev != buffer[0]) {
                    prev = buffer[0];
                    printf("buffer[0] changed to %#x by the other Master Board\n", buffer[0]);
                }
        scheduler_add_task(new terminalTask(PRIORITY_HIGH));
        scheduler_start();
  }