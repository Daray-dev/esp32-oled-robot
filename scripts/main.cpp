#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FluxGarage_RoboEyes.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
RoboEyes<Adafruit_SSD1306> roboEyes(display);

void setup() {
  Wire.begin(21, 22);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 30);

  roboEyes.setAutoblinker(ON, 3, 2);   // auto blinking
  roboEyes.setIdleMode(ON, 2, 2);      // 👈 THIS is your "search around"
}

void loop() {
  roboEyes.update();
}