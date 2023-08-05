/*
	I2C class public methods
*/

#include <Arduino.h>
#include <Wire.h>
#include "I2C.h"

#pragma region I²C command functions -------------------------------------------

void I2C::Cmd(int address, byte cmd)
{
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.endTransmission();
}

void I2C::Cmd(int address, byte cmd, byte param)
{
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param);
	Wire.endTransmission();
}

void I2C::Cmd(int address, byte cmd, byte param1, byte param2)
{
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param1);
	Wire.write(param2);
	Wire.endTransmission();
}

void I2C::Cmd(int address, byte cmd, byte param1, byte param2, byte param3)
{
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param1);
	Wire.write(param2);
	Wire.write(param3);
	Wire.endTransmission();
}

void I2C::Cmd(int address, byte cmd, byte param1, byte param2, byte param3, byte param4)
{
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param1);
	Wire.write(param2);
	Wire.write(param3);
	Wire.write(param4);
	Wire.endTransmission();
}

void I2C::Cmd(int address, int cmd, char *param)
{
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param);
	Wire.endTransmission();
}

#pragma endregion --------------------------------------------------------------