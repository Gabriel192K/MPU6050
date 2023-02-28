/*
 * Reading Raw Values.cpp
 *
 * Created: 2/18/2023 4:38:43 PM
 * Author : rotes
 */ 

#include "USART\USART.h"
#include "MPU6050\MPU6050.h"

MPU6050 mpu(&TWI, 0x68);

int main(void)
{
    USART.begin(115200);
    USART.printP(PSTR("MPU6050 Raw Values Example\n"));
    USART.printP((mpu.begin()) ? PSTR("MPU6050 started\n") : PSTR("MPU6050 didn't started\n"));
    while (1) 
    {
        int16_t x, y, z;
        mpu.readAccelerometer(&x, &y, &z);
        USART.printf("Ax: %hd, Ay: %hd, Ay: %hd\n", x, y, z);
        Time.delayMillis(1000);
    }
}

