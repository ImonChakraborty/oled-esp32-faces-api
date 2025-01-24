#ifndef _EYEVARIATION_h
#define _EYEVARIATION_h

#include <Arduino.h>
#include "Animations.h"
#include "EyeConfig.h"

class EyeVariation {
public:
	EyeVariation();

	EyeConfig* Input;
	EyeConfig Output;

	TrapeziumPulseAnimation Animation;

	EyeConfig Values;
	void Clear();

	void SetInterval(uint16_t t0, uint16_t t1, uint16_t t2, uint16_t t3, uint16_t t4);

	void Update();
	void Apply(float t);
};

#endif