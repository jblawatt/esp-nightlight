#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define LIGHT_PIN 25
#define MOTION_INPUT_PIN 26
#define NUM_PIXELS 60
#define LOOP_DELAY 500

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LIGHT_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.println("initializing...");
  pinMode(MOTION_INPUT_PIN, INPUT);
  Serial.begin(9600);
  pixels.begin();
  Serial.println("done");
}

void setLEDColor(uint32_t color, uint32_t delay_ms)
{
  for (int i = 0; i < NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, color);
    pixels.show();
    if (delay_ms > 0)
    {
      delay(delay_ms);
    }
  }
}

void loop()
{
  if (digitalRead(MOTION_INPUT_PIN) == HIGH)
  {
    Serial.println("motion");
    setLEDColor(pixels.Color(255, 0, 0), 20); // RED
  }
  else
  {
    Serial.println("no motion");
    setLEDColor(pixels.Color(0, 0, 0), 20); // OFF
  }
  delay(LOOP_DELAY);
}
