#ifndef _EYECONFIG_h
#define _EYECONFIG_h

#include <Arduino.h>
struct EyeConfig
{
	int16_t OffsetX;
	int16_t OffsetY;

 	int16_t Height;
	int16_t Width;

	float Slope_Top;
	float Slope_Bottom;

	int16_t Radius_Top;
	int16_t Radius_Bottom;

	int16_t Inverse_Radius_Top;
	int16_t Inverse_Radius_Bottom;

	int16_t Inverse_Offset_Top;
	int16_t Inverse_Offset_Bottom;
};

#endif