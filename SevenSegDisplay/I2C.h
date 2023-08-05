
#ifndef ftmodules_h
#define ftmodules_h

#include <Arduino.h>

class I2C
{
	public:
	static void Cmd(int address, byte cmd);
	static void Cmd(int address, byte cmd, byte param);
	static void Cmd(int address, byte cmd, byte param1, byte param2);
	static void Cmd(int address, byte cmd, byte param1, byte param2, byte param3);
	static void Cmd(int address, byte cmd, byte param1, byte param2, byte param3, byte param4);
	static void Cmd(int address, int cmd, char *param);
};

// ----------------------------- Seven-segment display

class SevenSegDisplay
{

	public:
	// void Clear(int address);
	// void Test(int address);
	// void Display(int address, char *str);
	// void Hold(int address, uint ms);
	// void Flash(int address, uint ms);
	// void Rotate(int address, uint ms);
	// void Stop(int address);

	// Commands for 7-segment display module
	enum Command
	{
		cmdBlank = 0x10,
		cmdTest = 0x11,
		cmdDisplay = 0x12,
		cmdFlash = 0x13,
		cmdRotate = 0x14,
		cmdHold = 0x15,
		cmdStop = 0x40,
	};

	static const byte maxDisplayChars = 80;
};

#endif // ftmodules_h