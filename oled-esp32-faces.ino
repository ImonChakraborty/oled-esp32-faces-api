#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>
#include "Face.h"

const char* ssid = "placeholder";     // Replace with your WiFi credentials
const char* password = "placeholder"; // Replace with your WiFi credentials

WebServer server(80);
const byte blinkPin = 16;
Face *face;

void setup(void) {
  Serial.begin(115200);
  Serial.println(__FILE__ __DATE__);
  pinMode(blinkPin, INPUT_PULLUP);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi. IP: ");
  Serial.println(WiFi.localIP());

  // Initialize face
  face = new Face(128, 64, 40);
  face->Expression.GoTo_Normal();
  
  // Set default emotion weights
  face->Behavior.SetEmotion(eEmotions::Normal, 1.0);
  face->Behavior.SetEmotion(eEmotions::Angry, 1.0);
  face->Behavior.SetEmotion(eEmotions::Sad, 0.5);
  face->Behavior.SetEmotion(eEmotions::Glee, 1.0);
  face->Behavior.SetEmotion(eEmotions::Happy, 1.0);
  face->Behavior.SetEmotion(eEmotions::Worried, 1.0);
  face->Behavior.SetEmotion(eEmotions::Focused, 1.0);
  face->Behavior.SetEmotion(eEmotions::Annoyed, 1.0);
  face->Behavior.SetEmotion(eEmotions::Surprised, 1.0);
  face->Behavior.SetEmotion(eEmotions::Skeptic, 1.0);
  face->Behavior.SetEmotion(eEmotions::Frustrated, 1.0);
  face->Behavior.SetEmotion(eEmotions::Unimpressed, 1.0);
  face->Behavior.SetEmotion(eEmotions::Sleepy, 1.0);
  face->Behavior.SetEmotion(eEmotions::Suspicious, 1.0);
  face->Behavior.SetEmotion(eEmotions::Squint, 1.0);
  face->Behavior.SetEmotion(eEmotions::Furious, 1.0);
  face->Behavior.SetEmotion(eEmotions::Scared, 1.0);
  face->Behavior.SetEmotion(eEmotions::Awe, 1.0);

  // Setup server routes
  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleEmotionAndPosition); 

  
  // Start server
  server.begin();

  face->RandomBehavior = false; 
  face->RandomBlink = true;     
  face->Blink.Timer.SetIntervalMillis(4000);
  face->RandomLook = false;     
}

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>ESP32 Face Control</h1>";
  html += "<p>Use /emotion/EMOTION/X/Y to control</p>";
  html += "<p>Example: /emotion/0/0.5/0.3</p>";
  html += "<p>Emotions: 0=Normal, 1=Angry, 2=Glee, etc.</p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleEmotionAndPosition() {
  String path = server.uri();
  
  if (!path.startsWith("/emotion/")) {
    server.send(404, "text/plain", "Not found");
    return;
  }

  String parts = path.substring(9); 
  int firstSlash = parts.indexOf('/');
  int secondSlash = parts.indexOf('/', firstSlash + 1);
  
  if (firstSlash == -1 || secondSlash == -1) {
    server.send(400, "text/plain", "Invalid format. Use /emotion/EMOTION/X/Y");
    return;
  }

  int emotion = parts.substring(0, firstSlash).toInt();
  float x = parts.substring(firstSlash + 1, secondSlash).toFloat();
  float y = parts.substring(secondSlash + 1).toFloat();

  x = constrain(x, -1.0, 1.0);
  y = constrain(y, -1.0, 1.0);
  emotion = constrain(emotion, 0, 17);

  face->Look.LookAt(x, y);
  face->Behavior.GoToEmotion(static_cast<eEmotions>(emotion));

  String response = "Set emotion: " + String(emotion) + ", x: " + String(x) + ", y: " + String(y);
  server.send(200, "text/plain", response);
}

void loop() {
  server.handleClient();
  
  if(!digitalRead(blinkPin)){
    face->DoBlink();
  }
  
  face->Update();
}