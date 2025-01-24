#ifndef _LOOKASSISTANT_h
#define _LOOKASSISTANT_h

#include <Arduino.h>
#include "EyeTransformation.h"
#include "AsyncTimer.h"

class Face;

class LookAssistant
{
 protected:
	Face&  _face;

 public:
	LookAssistant(Face& face);

	Transformation transformation;

	AsyncTimer Timer;

	void LookAt(float x, float y);
	void Update();
};

#endif

