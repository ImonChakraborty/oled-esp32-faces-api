#include "BlinkAssistant.h"
#include "Face.h"

BlinkAssistant::BlinkAssistant(Face& face) : _face(face), Timer(3500) {
	Timer.Start();
}

void BlinkAssistant::Update() {
	Timer.Update();

	if (Timer.IsExpired()) {
		Blink();
	}
}

void BlinkAssistant::Blink() {
	_face.LeftEye.BlinkTransformation.Animation.Restart();
	_face.RightEye.BlinkTransformation.Animation.Restart();
	Timer.Reset();
}