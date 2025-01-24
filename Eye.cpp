#include "Eye.h"

Eye::Eye(Face& face) : _face(face) {

  this->IsMirrored = false;

	ChainOperators();
	Variation1.Animation._t0 = 200;
	Variation1.Animation._t1 = 200;
	Variation1.Animation._t2 = 200;
	Variation1.Animation._t3 = 200;
	Variation1.Animation._t4 = 0;
	Variation1.Animation.Interval = 800;

	Variation2.Animation._t0 = 0;
	Variation2.Animation._t1 = 200;
	Variation2.Animation._t2 = 200;
	Variation2.Animation._t3 = 200;
	Variation2.Animation._t4 = 200;
	Variation2.Animation.Interval = 800;
}

void Eye::ChainOperators() {
	Transition.Origin = &Config;
	Transformation.Input = &Config;
	Variation1.Input = &(Transformation.Output);
	Variation2.Input = &(Variation1.Output);
	BlinkTransformation.Input = &(Variation2.Output);
	FinalConfig = &(BlinkTransformation.Output);
}

void Eye::Update() {
	Transition.Update();
	Transformation.Update();
	Variation1.Update();
	Variation2.Update();
	BlinkTransformation.Update();
}

void Eye::Draw() {
	Update();
	EyeDrawer::Draw(CenterX, CenterY, FinalConfig);
}

void Eye::ApplyPreset(const EyeConfig config) {
	Config.OffsetX = this->IsMirrored ? -config.OffsetX : config.OffsetX;
	Config.OffsetY = -config.OffsetY;
	Config.Height = config.Height;
	Config.Width = config.Width;
	Config.Slope_Top = this->IsMirrored ? config.Slope_Top : -config.Slope_Top;
	Config.Slope_Bottom = this->IsMirrored ? config.Slope_Bottom : -config.Slope_Bottom;
	Config.Radius_Top = config.Radius_Top;
	Config.Radius_Bottom = config.Radius_Bottom;
	Config.Inverse_Radius_Top = config.Inverse_Radius_Top;
	Config.Inverse_Radius_Bottom = config.Inverse_Radius_Bottom;

	Transition.Animation.Restart();
}

void Eye::TransitionTo(const EyeConfig config) {
	Transition.Destin.OffsetX = this->IsMirrored ? -config.OffsetX : config.OffsetX;
	Transition.Destin.OffsetY = -config.OffsetY;
	Transition.Destin.Height = config.Height;
	Transition.Destin.Width = config.Width;
	Transition.Destin.Slope_Top = this->IsMirrored ? config.Slope_Top : -config.Slope_Top;
	Transition.Destin.Slope_Bottom = this->IsMirrored ? config.Slope_Bottom : -config.Slope_Bottom;
	Transition.Destin.Radius_Top = config.Radius_Top;
	Transition.Destin.Radius_Bottom = config.Radius_Bottom;
	Transition.Destin.Inverse_Radius_Top = config.Inverse_Radius_Top;
	Transition.Destin.Inverse_Radius_Bottom = config.Inverse_Radius_Bottom;

	Transition.Animation.Restart();
}