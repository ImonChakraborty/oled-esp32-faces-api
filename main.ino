#include <Wire.h>
#include "Face.h"

const byte blinkPin = 16;
Face *face;

void setup(void) {
  Serial.begin(115200);
  Serial.println(__FILE__ __DATE__);
  pinMode(blinkPin, INPUT_PULLUP);

  face = new Face(128, 64, 40);
  face->Expression.GoTo_Normal();

  face->RandomBehavior = true;
  face->RandomBlink = true;
  face->Blink.Timer.SetIntervalMillis(4000);
  face->RandomLook = true; // Automatically choose a new random direction to look
}

void loop(){
  // Automatically set random look directions every 500ms
  static int lastMoveTime;
  if(millis() - lastMoveTime > 500) {
    float x = random(-100, 100) / 100.0;
    float y = random(-100, 100) / 100.0;
    face->Look.LookAt(x, y);
    lastMoveTime = millis();
  }

  // Automatically blink at random intervals
  if(!digitalRead(blinkPin)){
    face->DoBlink();
  }

  // Automatically switch between emotions at random intervals
  static int lastEmotionChangeTime;
  if(millis() - lastEmotionChangeTime > 5000) {
    int randomEmotion = random(0, 18); // Assuming there are 18 emotions
    face->Behavior.SetEmotion(static_cast<eEmotions>(randomEmotion), 1.0);
    lastEmotionChangeTime = millis();
  }

  face->Update();
}
