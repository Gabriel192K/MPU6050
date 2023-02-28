#ifndef __MPU6050_COMMANDS_H__
#define __MPU6050_COMMANDS_H__

#define ACR ((uint8_t)0x1C)       // Accelerometer Config Register
#define AFS_SEL1 ((uint8_t)4) // Acccelerometer Full Scale Select Bit 1
#define AFS_SEL0 ((uint8_t)3) // Acccelerometer Full Scale Select Bit 0
// | AFS_SEL1 | AFS_SEL0 | Full Scale Range |
// |    0     |    0     |      +- 2g       |
// |    0     |    1     |      +- 4g       |
// |    1     |    0     |      +- 8g       |
// |    1     |    1     |      +- 16g      |

#define AXOHR ((uint8_t)0x3B) // Accelerometer X Axis Out MSB Register
#define AXOLR ((uint8_t)0x3C) // Accelerometer X Axis Out LSB Register
#define AYOHR ((uint8_t)0x3D) // Accelerometer Y Axis Out MSB Register
#define AYOLR ((uint8_t)0x3E) // Accelerometer Y Axis Out LSB Register
#define AZOHR ((uint8_t)0x3F) // Accelerometer Z Axis Out MSB Register
#define AZOLR ((uint8_t)0x40) // Accelerometer Z Axis Out LSB Register

#define TOHR ((uint8_t)0x41) // Temperature Output MSB Register
#define TOLR ((uint8_t)0x42) // Temperature Output LSB Register

#define GXOHR ((uint8_t)0x43) // Gyroscope X Axis Out MSB Register
#define GXOLR ((uint8_t)0x44) // Gyroscope X Axis Out LSB Register
#define GYOHR ((uint8_t)0x45) // Gyroscope Y Axis Out MSB Register
#define GYOLR ((uint8_t)0x46) // Gyroscope Y Axis Out LSB Register
#define GZOHR ((uint8_t)0x47) // Gyroscope Z Axis Out MSB Register
#define GZOLR ((uint8_t)0x48) // Gyroscope Z Axis Out LSB Register

#define PMGMR1   ((uint8_t)0x6B)    // Power Management Register 1
#define RST      ((uint8_t)7) // Device Reset Bit
#define SLP      ((uint8_t)6) // Deivce Sleep Bit
#define CYC      ((uint8_t)5) // Device Cycle Bit
#define TOFF     ((uint8_t)3) // Temperature Sensor Disable Bit
#define CLK_SEL2 ((uint8_t)2) // Clock Select Bit 2
#define CLK_SEL1 ((uint8_t)1) // Clock Select Bit 1
#define CLK_SEL0 ((uint8_t)0) // Clock Select Bit 0

#define PMGMR2     ((uint8_t)0x6C)      // Power Management Register 2
#define WAKE_CTRL1 ((uint8_t)7) // Wake-up Control Bit 1
#define WAKE_CTRL0 ((uint8_t)6) // Wake-up Control Bit 0
#define STBY_AX    ((uint8_t)5) // Standby Accelerometer X Axis
#define STBY_AY    ((uint8_t)4) // Standby Accelerometer Y Axis
#define STBY_AZ    ((uint8_t)3) // Standby Accelerometer Z Axis
#define STBY_GX    ((uint8_t)2) // Standby Gyroscope X Axis
#define STBY_GY    ((uint8_t)1) // Standby Gyroscope Y Axis
#define STBY_GZ    ((uint8_t)0) // Standby Gyroscope Z Axis

#endif
