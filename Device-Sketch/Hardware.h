#pragma once

#include <SD.h>
#include <Adafruit_MotorShield.h>
#include <Wire.h> //Wire library

namespace Hardware {

/* LED pin number */
extern int pin_LED;

/* Pressure Transducer pins */
extern int pin_P1; /* Analog pin to read Voltage from for pressure tranny in oxy tank*/
extern int pin_P2; /*analog pin to read off of for comb. chamber pressure*/

/*digital pins for  thermocouples*/
extern int8_t pin_T1_DO;
extern int8_t pin_T1_CS;
extern int8_t pin_T1_CLK;
extern int8_t pin_T2_DO;
extern int8_t pin_T2_CS;
extern int8_t pin_T2_CLK;
extern int8_t pin_T3_DO;
extern int8_t pin_T3_CS;
extern int8_t pin_T3_CLK;

/*chip select pin for SD logger*/
extern const int sdcard_chipSelect;

//NEW CODE
/*data file for logging to sd*/
extern File sdcard_datafile;

/* XBee RX, TX pins */
// Connect DIN to pin 18 ,and DOUT to pin 19

/* Stepper Moteror

  /* LED Data */
extern bool is_LED_on;

/**
  Updates data variables by calling functions that control data
  acquisition from connected devices

  INPUT
  void

  OUTPUT
  Hexidecimal value, one activated for each datum obtained successfully
         0x00000001 - PRESSURE_OXIDIZER
         0x00000010 - PRESSURE_COMBUSTION
         0x00000100 - TEMPERATURE_OXIDIZER
         0x00001000 - TEMPERATURE_COMBUSTION
         0x00010000 - THRUST
*/
unsigned char update_data();

/**
   Creates a file to save data to
*/
void sdcard_openfile();

/**
   Closes currently open save file
*/
void sdcard_closefile();

/**
   Saves the data values to a line on a file in the SD card
*/
void sdcard_write(unsigned int datatype);

/**
   Initializes the stepper motor
*/
void initializeStepperMotor();

/**
   Closes the stepper motor
*/
void closeStepperMotor();

/**
   Opens the stepper motor
*/
void openStepperMotor();

/**
	reads pressure in oxidizer tank
	@return float = pressure in oxy tank in psi
*/
float get_pressure_1_data();


/**
   reads pressure in combustion chamber in psi
   @return float = pressure in chamber (psi)
*/
float get_pressure_2_data();

/**
  Turns on the LED

  INPUT
  bool output -> true to output "LED ON", true by default
*/
void turn_LED_on(bool output = false);

/**
  Turns off the LED

  INPUT
  bool output -> true to output "LED OFF", true by default
*/
void turn_LED_off(bool output = false);

}






