#ifndef _EYETRANSITION_h
#define _EYETRANSITION_h

#include <Arduino.h>
#include "Animations.h"
#include "EyeConfig.h"

class EyeTransition {
public:
	EyeTransition();

	EyeConfig* Origin;
	EyeConfig Destin;

	RampAnimation Animation;

	void Update();
	void Apply(float t);
};

#endif

