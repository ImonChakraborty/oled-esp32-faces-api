#ifndef _FACEBEHAVIOR_h
#define _FACEBEHAVIOR_h

#include <Arduino.h>
#include "FaceEmotions.hpp"
#include "AsyncTimer.h"

class Face;

class FaceBehavior
{
 protected:
	Face&  _face;

 public:
	FaceBehavior(Face& face);

	eEmotions CurrentEmotion;

	float Emotions[eEmotions::EMOTIONS_COUNT];

	AsyncTimer Timer;

	void SetEmotion(eEmotions emotion, float value);
	float GetEmotion(eEmotions emotion);

	void Clear();
	void Update();
	eEmotions GetRandomEmotion();

	void GoToEmotion(eEmotions emotion);
};

#endif

