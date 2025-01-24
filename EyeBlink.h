#ifndef _EYEBLINK_h
#define _EYEBLINK_h

#include <Arduino.h>
#include "Animations.h"
#include "EyeConfig.h"

class EyeBlink {
 protected:

public:
	EyeBlink();

	EyeConfig* Input;
	EyeConfig Output;

	TrapeziumAnimation Animation;

	int32_t BlinkWidth = 60;
	int32_t BlinkHeight = 2;

	void Update();
	void Apply(float t);
};

#endif