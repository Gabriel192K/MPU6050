#ifndef __MPU6050_H__
#define __MPU6050_H__

#include "TWI/TWI.h"
#include "MPU6050 Commands.h"

class MPU6050
{

    public:
        MPU6050(__TWI__* twi, const uint8_t address);
        uint8_t begin                   (void);
        uint8_t isConnected             (void);
        void    readAccelerometer       (int16_t* x, int16_t* y, int16_t* z);
		void    readGyroscope           (int16_t* x, int16_t* y, int16_t* z);
		void    readTemperature         (int16_t* t);
		void    enableTemperatureSensor (void);
		void    disableTemperatureSensor(void);
    private:
        __TWI__* twi;
        uint8_t address;
};

#endif
