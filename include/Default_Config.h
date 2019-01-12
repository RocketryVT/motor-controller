#ifndef DEFAULT_CONFIG_H
#define DEFAULT_CONFIG_H

#define test_str_length 1024
#define __PROGRAM_VERSION__ "MOTOR CONTROL 1.0.0"
#define __LF__ 10 // Newline character

#include <chrono>

/* XBee RX, TX pins */
// Connect DIN to pin 18 ,and DOUT to pin 19

namespace Default_Config {

	/* Baud Rates */
	extern unsigned long XBEE_BAUD;
	extern unsigned long SD_BAUD;

	/* Data Transmission Type */
	extern unsigned int DATA_OUT_TYPE;
	
    extern std::chrono::time_point<std::chrono::steady_clock>
        TIME, START_TIME, DATA_TIME;

    extern std::chrono::milliseconds
        /* Device interface control variables */
        LOOP_PERIOD_MS,
        XBeeWrite_period_ms,
        checkbuffer_period_ms,
        /* Data Timing */
        PRESSURE_PERIOD_MS,
        TEMPERATURE_PERIOD_MS,
        LOADCELL_PERIOD_MS;
}

namespace Pins_Config {
	
	/* Pressure Transducer pins */
	extern unsigned int pin_P1; /* Analog pin to read Voltage from for pressure tranny in oxy tank*/
	extern unsigned int pin_P2; /*analog pin to read off of for comb. chamber pressure*/
	
	/* Thermocouple Pins*/
	extern unsigned int pin_T1_DO;
	extern unsigned int pin_T1_CS;
	extern unsigned int pin_T1_CLK;
	extern unsigned int pin_T2_DO;
	extern unsigned int pin_T2_CS;
	extern unsigned int pin_T2_CLK;
	extern unsigned int pin_T3_DO;
	extern unsigned int pin_T3_CS;
	extern unsigned int pin_T3_CLK;
	
	/* Load Cell Pins */
	extern unsigned int LOADCELL_DOUT;
	extern unsigned int LOADCELL_CLK;
	extern float loadcell_calibration_factor;

	/* LED pin number */
	extern unsigned int pin_LED;
}

namespace State_Data {
	/* Data variables*/
	extern int STATUS;
	extern float DATA_P1;  // Pressure 1
	extern float DATA_P2;  // Pressure 2
	extern float DATA_T1;  // Temperature 1
	extern float DATA_T2;  // Temperature 2
	extern float DATA_T3;  // Temperature 3
	extern float DATA_THR; // Thrust / Force
	extern unsigned char NEW_DATA;
	extern unsigned int MODE;
	
	/* Data Timing Control */
    extern std::chrono::time_point<std::chrono::steady_clock>
	    LAST_PRESSURE_TIME_US,
	    LAST_TEMPERATURE_TIME_US,
	    LAST_LOADCELL_TIME_US;
}

#endif // DEFAULT_CONFIG_H
