#include "EyeVariation.h"

EyeVariation::EyeVariation() : Animation(0, 1000, 0, 1000, 0){}

void EyeVariation::Clear() {
	Values.OffsetX = 0;
	Values.OffsetY = 0;
	Values.Height = 0;
	Values.Width = 0;
	Values.Slope_Top = 0;
	Values.Slope_Bottom = 0;
	Values.Radius_Top = 0;
	Values.Radius_Bottom = 0;
	Values.Inverse_Radius_Top = 0;
	Values.Inverse_Radius_Bottom = 0;
	Values.Inverse_Offset_Top = 0;
	Values.Inverse_Offset_Bottom = 0;
}

void EyeVariation::Update() {
	auto t = Animation.GetValue();
	Apply(2.0 * t - 1.0);
}

void EyeVariation::Apply(float t) {
	Output.OffsetX = Input->OffsetX + Values.OffsetX * t;
	Output.OffsetY = Input->OffsetY + Values.OffsetY * t;
	Output.Height = Input->Height + Values.Height * t;;
	Output.Width = Input->Width + Values.Width * t;
	Output.Slope_Top = Input->Slope_Top + Values.Slope_Top * t;
	Output.Slope_Bottom = Input->Slope_Bottom + Values.Slope_Bottom * t;
	Output.Radius_Top = Input->Radius_Top + Values.Radius_Top * t;
	Output.Radius_Bottom = Input->Radius_Bottom + Values.Radius_Bottom * t;
	Output.Inverse_Radius_Top = Input->Inverse_Radius_Top + Values.Inverse_Radius_Top * t;
	Output.Inverse_Radius_Bottom = Input->Inverse_Radius_Bottom + Values.Inverse_Radius_Bottom * t;
	Output.Inverse_Offset_Top = Input->Inverse_Offset_Top + Values.Inverse_Offset_Top * t;
	Output.Inverse_Offset_Bottom = Input->Inverse_Offset_Bottom + Values.Inverse_Offset_Bottom * t;;
}