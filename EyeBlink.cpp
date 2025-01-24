#include "EyeBlink.h"


EyeBlink::EyeBlink() : Animation(40, 100, 40) { }

void EyeBlink::Update() {
	auto t = Animation.GetValue();
	if(Animation.GetElapsed() > Animation.Interval) t = 0.0;
	Apply(t * t);
}


void EyeBlink::Apply(float t) {
	Output.OffsetX = Input->OffsetX;
	Output.OffsetY = Input->OffsetY;

	Output.Width = (BlinkWidth - Input->Width) * t + Input->Width;
	Output.Height = (BlinkHeight - Input->Height) * t + Input->Height;

	Output.Slope_Top = Input->Slope_Top * (1.0 - t);
	Output.Slope_Bottom = Input->Slope_Bottom * (1.0 - t);
	Output.Radius_Top = Input->Radius_Top * (1.0 - t);
	Output.Radius_Bottom = Input->Radius_Bottom * (1.0 - t);
	Output.Inverse_Radius_Top = Input->Inverse_Radius_Top * (1.0 - t);
	Output.Inverse_Radius_Bottom = Input->Inverse_Radius_Bottom * (1.0 - t);
	Output.Inverse_Offset_Top = Input->Inverse_Offset_Top * (1.0 - t);
	Output.Inverse_Offset_Bottom = Input->Inverse_Offset_Bottom * (1.0 - t);
}

