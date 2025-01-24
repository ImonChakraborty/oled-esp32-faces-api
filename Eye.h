#ifndef _EYE_h
#define _EYE_h

#include <Arduino.h>
#include "Common.h"
#include "Animations.h"
#include "EyeConfig.h"
#include "EyeDrawer.h"
#include "EyeTransition.h"
#include "EyeTransformation.h"
#include "EyeVariation.h"
#include "EyeBlink.h"
#include "EyeVariation.h"

class Face;

class Eye {
  protected:
    Face& _face;

    void Update();
    void ChainOperators();

  public:
    Eye(Face& face);

    uint16_t CenterX;
    uint16_t CenterY;
    bool IsMirrored = false;

    EyeConfig Config;
    EyeConfig* FinalConfig;

    EyeTransition Transition;
    EyeTransformation Transformation;
    EyeVariation Variation1;
    EyeVariation Variation2;
    EyeBlink BlinkTransformation;

    void ApplyPreset(const EyeConfig preset);
    void TransitionTo(const EyeConfig preset);
    void Draw();
};

#endif