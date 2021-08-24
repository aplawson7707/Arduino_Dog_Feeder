/* FILE:    HCPCA9685_Servo_Example
   DATE:    10/06/16
   VERSION: 0.1
   AUTHOR:  Andrew Davies

   Sketch created by Hobby Components Ltd (HOBBYCOMPONENTS.COM)
   
10/06/16 version 0.1: Original version


This example demonstrates how to use the HCPCA9685 library together with the PCA9685
to control up to 16 servos. The sketch will initialise the library putting it into 
'servo mode' and then will continuously sweep one servo connected to PWM output 0 
back and forth. The example has been written particularly for the 16 Channel 12-bit 
PWM Servo Motor Driver Module (HCMODU0097) available from hobbycomponents.com 

To use the module connect it to your Arduino as follows:

PCA9685...........Uno/Nano
GND...............GND
OE................N/A
SCL...............A5
SDA...............A4
VCC...............5V

External 5V Power for the servo(s) can be supplied by the V+ and GND input of the 
screw terminal block.

/* Include the HCPCA9685 library */
#include "HCPCA9685.h"

/* I2C slave address for the device/module. For the HCMODU0097 the default I2C address
   is 0x40 */
#define  I2CAdd 0x40


/* Create an instance of the library */
HCPCA9685 HCPCA9685(I2CAdd);    // create an instance of the library


void setup() 
{
  /* Initialise the library and set it to 'servo mode' */ 
  HCPCA9685.Init(SERVO_MODE);   // start library and set to servo mode

  /* Wake the device up */
  HCPCA9685.Sleep(false);       // wake the pca9685 control board
}

//HCPCA9685.Servo(servo #, position)

void loop() 
{
  delay(3000);                  // wait three seconds before first rotation
  
  HCPCA9685.Servo(3, 80);       // rotate the feeder one full rotation
  delay(4110);
  
  HCPCA9685.Servo(3, 190);      // stop value is position 190
//  delay(5000);                // 5 seconds (x * 1000 for seconds-to-milliseconds)
//  delay(1800000);             // 30 minutes (x * 60000 for minutes-to-milliseconds)
  delay(43200000);             // 12 hours (x * 3600000 for hours-to-milliseconds)
}
