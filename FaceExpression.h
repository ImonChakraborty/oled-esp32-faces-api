#ifndef _FACEEXPRESSION_h
#define _FACEEXPRESSION_h

#include <Arduino.h>

class Face;

class FaceExpression {
  protected:
    Face&  _face;

  public:
    FaceExpression(Face& face);

    void ClearVariations();

    void GoTo_Normal();
    void GoTo_Angry();
    void GoTo_Glee();
    void GoTo_Happy();
    void GoTo_Sad();
    void GoTo_Worried();
    void GoTo_Focused();
    void GoTo_Annoyed();
    void GoTo_Surprised();
    void GoTo_Skeptic();
    void GoTo_Frustrated();
    void GoTo_Unimpressed();
    void GoTo_Sleepy();
    void GoTo_Suspicious();
    void GoTo_Squint();
    void GoTo_Furious();
    void GoTo_Scared();
    void GoTo_Awe();
};

#endif