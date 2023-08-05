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

void Display::ConvertNumber(char *buffer, long value, int lastPos = (DISPLAYCHARS - 1))
{
    bool isNegative = (value < 0);

    if(isNegative) {
        value = -value;
    }

    for(int i = lastPos; i >= (isNegative ? 1 : 0); i--, value /= 10) {
        // buffer[i] = '0' + value % 10;
		buffer[i] = (value == 0 && i != lastPos) ? ' ' : '0' + value % 10;
    }

    if(isNegative && lastPos >= 1) {
        buffer[lastPos - 1] = '-';
    }
}


#pragma endregion --------------------------------------------------------------
