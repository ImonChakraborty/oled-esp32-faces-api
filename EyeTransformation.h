#ifndef _EYETRANSFORMATION_h
#define _EYETRANSFORMATION_h

#include <Arduino.h>
#include "Animations.h"
#include "EyeConfig.h"

struct Transformation
{
	float MoveX = 0.0;
	float MoveY = 0.0;
	float ScaleX = 1.0;
	float ScaleY = 1.0;
};

class EyeTransformation
{
public:
	EyeTransformation();

	EyeConfig* Input;
	EyeConfig Output;

	Transformation Origin;
	Transformation Current;
	Transformation Destin;

	RampAnimation Animation;

	void Update();
	void Apply();
	void SetDestin(Transformation transformation);
};

#endif

