#ifndef _BLINKASSISTANT_h
#define _BLINKASSISTANT_h

#include <Arduino.h>
#include "Animations.h"
#include "AsyncTimer.h"

class Face;

class BlinkAssistant {
 protected:
	Face&  _face;

 public:
	BlinkAssistant(Face& face);

	AsyncTimer Timer;

	void Update();
	void Blink();
};

#endif