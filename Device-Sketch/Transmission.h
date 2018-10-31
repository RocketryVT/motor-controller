#pragma once

namespace Transmission {

	/**
	* Compiles data to a char array so that it can be pushed to the 
	* serial port directly. Also this makes it easier to compute a
	* checksum on the data
	*
	* INPUTS
	* char* str -> pointer to char array
	* unsigned int type -> data transmission packet type (see documentation)
	* unsigned int len -> lenght of data packet (see documentation)
	* 
	* OUTPUTS
	* void (change this to checksum eventually)
	*/
	void buildPacket(unsigned char* str, unsigned int* len, unsigned int type);

	/**
	* Converts a series of unsigned char values to a 
	* 32 bit floating point value to four bytes. The most
	* significant byte is transmitted first.
	*
	* INPUTS
	* char* a -> Most significant byte
	* char* b -> 2nd most significant byte
	* char* c -> 3rd most significant byte
	* char* d -> Least significant byte
	*
	* OUTPUTS
	* float -> Floating point value
	*/
	float charsToFloat(unsigned char a, unsigned char b, unsigned char c, unsigned char d);

	/**
	 * Converts a 32 bit floating point value to four bytes by
	 * assigning values to the non-const char pointers. The most
	 * significant byte is transmitted first.
	 *
	 * INPUTS
	 * float x -> floating point value
	 * char* a -> Most significant byte
	 * char* b -> 2nd most significant byte
	 * char* c -> 3rd most significant byte 
	 * char* d -> Least significant byte
	 * 
	 * OUTPUTS
	 * N/A
	 */
	void floatToChars(float x, unsigned char* a, unsigned char* b, unsigned char* c, unsigned char* d);

}