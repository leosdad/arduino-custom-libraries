// -----------------------------------------------------------------------------

// I²C display wrapper commands
// Rubem Pechansky 2021-2023

// -----------------------------------------------------------------------------

#ifndef display_h
#define display_h

#include "I2C.h"

// Constants for other modules

#define SEVENSEGDISPLAY_ADR		0x09
#define DISPLAYCHARS			6

class Display
{
  public:
	static void Init(bool test);
	static void Clear();
	static void Test();
	static void Show(char *str);
	// static void Hold(unsigned int ms);
	static void Flash(unsigned int ms);
	static void Rotate(unsigned int ms);
	static void Stop();
	static void U2c(char *buffer, unsigned long value);
};


#endif // display_h
