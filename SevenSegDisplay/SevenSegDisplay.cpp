// -----------------------------------------------------------------------------

// I²C display wrapper commands
// Rubem Pechansky 2021-2023

// -----------------------------------------------------------------------------

#include <Arduino.h>
#include "SevenSegDisplay.h"

#pragma region Constants -------------------------------------------------------

#define DISPLAY_INIT_TIME		200

#pragma endregion --------------------------------------------------------------

#pragma region Methods ---------------------------------------------------------

void Display::Init(bool test)
{
	Display::Clear();
	if(test) {
		Display::Test();
	}
	delay(DISPLAY_INIT_TIME);
}

void Display::Clear()
{
	I2C::Cmd(SEVENSEGDISPLAY_ADR, SevenSegDisplay::cmdBlank);
}

void Display::Test()
{
	I2C::Cmd(SEVENSEGDISPLAY_ADR, SevenSegDisplay::cmdTest);
}

void Display::Show(char *str)
{
	I2C::Cmd(SEVENSEGDISPLAY_ADR, SevenSegDisplay::cmdDisplay, str);
}

// void Display::Hold(unsigned int ms)
// {
// 	I2C::Cmd(SEVENSEGDISPLAY_ADR, SevenSegDisplay::cmdHold, lowByte(ms), highByte(ms));
// }

void Display::Flash(unsigned int ms)
{
	I2C::Cmd(SEVENSEGDISPLAY_ADR, SevenSegDisplay::cmdFlash, lowByte(ms), highByte(ms));
}

void Display::Rotate(unsigned int ms)
{
	I2C::Cmd(SEVENSEGDISPLAY_ADR, SevenSegDisplay::cmdRotate, ms);
}

void Display::Stop()
{
	I2C::Cmd(SEVENSEGDISPLAY_ADR, SevenSegDisplay::cmdStop);
}

// https://forum.arduino.cc/t/right-justify/93157/10

void Display::U2c(char *buffer, unsigned long value)
{
	for(int i = DISPLAYCHARS - 1; i >= 0; i--) {
		buffer[i] = (value == 0 && i != DISPLAYCHARS - 1) ? ' ' : '0' + value % 10;
		value /= 10;
	}
}

#pragma endregion --------------------------------------------------------------
