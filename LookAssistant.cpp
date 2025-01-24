#include "LookAssistant.h"
#include "Face.h"
#include "EyeTransformation.h"

LookAssistant::LookAssistant(Face& face) : _face(face), Timer(4000)
{
	Timer.Start();
}

void LookAssistant::LookAt(float x, float y)
{
	int16_t moveX_x;
	int16_t moveY_x;
	int16_t moveY_y;
	float scaleY_x;
	float scaleY_y;

  // What is this witchcraft...?!
	moveX_x = -25 * x;
	moveY_x = -3 * x;
	moveY_y = 20 * y;
	scaleY_x = 1.0 - x * 0.2;
	scaleY_y = 1.0 - (y > 0 ? y : -y) * 0.4;

	transformation.MoveX = moveX_x;
	transformation.MoveY = moveY_y; //moveY_x + moveY_y;
	transformation.ScaleX = 1.0;
	transformation.ScaleY = scaleY_x * scaleY_y;
	_face.RightEye.Transformation.SetDestin(transformation);

	moveY_x = +3 * x;
	scaleY_x = 1.0 + x * 0.2;
	transformation.MoveX = moveX_x;
	transformation.MoveY = + moveY_y; //moveY_x + moveY_y;
	transformation.ScaleX = 1.0;
	transformation.ScaleY = scaleY_x * scaleY_y;
	_face.LeftEye.Transformation.SetDestin(transformation);

	_face.RightEye.Transformation.Animation.Restart();
	_face.LeftEye.Transformation.Animation.Restart();
}

void LookAssistant::Update() {
	Timer.Update();

	if (Timer.IsExpired()) {
		Timer.Reset();
		auto x = random(-50, 50);
		auto y = random(-50, 50);
		LookAt((float)x  / 100, (float)y / 100);
	}

}
