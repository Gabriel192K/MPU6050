#include "MPU6050.h"

/*********************************************
Function: MPU6050()
Purpose:  Constructor to MPU6050 class
Input:    Address of TWI bus and address of device
Return:   None
*********************************************/
MPU6050::MPU6050(__TWI__* twi, const uint8_t address)
{
    this->twi = twi;
    this->address = address;
}

/*********************************************
Function: begin()
Purpose:  Begin communication with MPU6050
Input:    None
Return:   Status of MPU6050 communication
*********************************************/
uint8_t MPU6050::begin(void)
{
    twi->begin();
    if (!this->isConnected()) return (0);
    this->disableTemperatureSensor();
    return (1);
}

/*********************************************
Function: isConnected()
Purpose:  Check communication with MPU6050
Input:    None
Return:   Status of MPU6050 communication
*********************************************/
uint8_t MPU6050::isConnected(void)
{
    uint8_t status = this->twi->beginTransmission(address);
    this->twi->endTransmission();
    return (status);
}

void MPU6050::readAccelerometer(int16_t* x, int16_t* y, int16_t* z)
{
    this->twi->beginTransmission(address);                                 // Begin transmission to address
    this->twi->write(AXOHR);                                               // Access accelerometer x axis upper register
    if (this->twi->requestFrom(address, (uint8_t)6) != (uint8_t)6) return; // Request data and check if data can be received
    *x = ((uint8_t)this->twi->read() << 8) | (uint8_t)this->twi->read();   // Read upper and lower registers one after another
    *y = ((uint8_t)this->twi->read() << 8) | (uint8_t)this->twi->read();   // Read upper and lower registers one after another
    *z = ((uint8_t)this->twi->read() << 8) | (uint8_t)this->twi->read();   // Read upper and lower registers one after another
    this->twi->endTransmission();                                          // End transmission
}

void MPU6050::readGyroscope(int16_t* x, int16_t* y, int16_t* z)
{
    this->twi->beginTransmission(address);                                 // Begin transmission to address
    this->twi->write(GXOHR);                                               // Access gyroscope x axis upper register
    if (this->twi->requestFrom(address, (uint8_t)6) != (uint8_t)6) return; // Request data and check if data can be received
    *x = ((uint8_t)this->twi->read() << 8) | (uint8_t)this->twi->read();   // Read upper and lower registers one after another
    *y = ((uint8_t)this->twi->read() << 8) | (uint8_t)this->twi->read();   // Read upper and lower registers one after another
    *z = ((uint8_t)this->twi->read() << 8) | (uint8_t)this->twi->read();   // Read upper and lower registers one after another
    this->twi->endTransmission();                                          // End transmission
}

void MPU6050::readTemperature(int16_t* t)
{
    this->twi->beginTransmission(address);                                 // Begin transmission to address
    this->twi->write(TOHR);                                                // Access temperature output upper register
    if (this->twi->requestFrom(address, (uint8_t)2) != (uint8_t)2) return; // Request data and check if data can be received
    *t = ((uint8_t)this->twi->read() << 8) | (uint8_t)this->twi->read();   // Read upper and lower registers one after another
    this->twi->endTransmission();                                          // End transmission
    *t = (*t / 340) + 37;                                                  // Calculate temperature in celsius
}

void MPU6050::enableTemperatureSensor (void)
{
    this->twi->beginTransmission(address);                                 // Begin transmission to address
    this->twi->write(PMGMR1);                                              // Access power management register 1
    if (this->twi->requestFrom(address, (uint8_t)1) != (uint8_t)1) return; // Request data and check if data can be received
    this->twi->write((uint8_t)((uint8_t)twi->read() & ~(1 << TOFF)));      /* Clear <TOFF> bit in <PMGMR1> */
    this->twi->endTransmission();                                          // End transmission
}

void MPU6050::disableTemperatureSensor(void)
{
    this->twi->beginTransmission(address);                                 // Begin transmission to address
    this->twi->write(PMGMR1);                                              // Access power management register 1
    if (this->twi->requestFrom(address, (uint8_t)1) != (uint8_t)1) return; // Request data and check if data can be received
    this->twi->write((uint8_t)((uint8_t)twi->read() | (1 << TOFF)));       /* Set <TOFF> bit in <PMGMR1> */
    this->twi->endTransmission();                                          // End transmission
}
