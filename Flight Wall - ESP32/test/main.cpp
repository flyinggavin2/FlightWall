#include <Arduino.h>
#include <WiFi.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>


const char* ssid = "ATTbCyA9G8";
const char* password = "t8j4z3272p#w8";

// put function declarations here:

// Panel dimensions
#define PANEL_WIDTH 128
#define PANEL_HEIGHT 64

MatrixPanel_I2S_DMA *dma_display = nullptr;

// :: is the scope resolution operator.
// i2s_pins is a struct type defined inside HUB75_I2S_CFG.
HUB75_I2S_CFG::i2s_pins pins = { 
    .r1 = 37,
    .g1 = 6,
    .b1 = 36,

    .r2 = 35,
    .g2 = 5,
    .b2 = 0,

    .a = 45,
    .b = 1,
    .c = 48,
    .d = 2,
    .e = 4,

    .lat = 38,
    .oe = 21,
    .clk = 47 // can be assigned just by numners but added designated intialization to better read 
};


void setup() 
{
  Serial.begin(115200);
  delay(1000);

  Serial.println("==============================");
  Serial.println("Flight Wall ESP32-S3");
  Serial.println("PlatformIO is working!");
  Serial.println("ESP32-S3 + HUB75 library");
  Serial.println("==============================");

  Serial.println("Connecting to Wi-Fi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
      delay(500);
      Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi connected!");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Create panel configuration
  HUB75_I2S_CFG mxconfig(
        PANEL_WIDTH,
        PANEL_HEIGHT,
        1,
        pins
  );

  // Create display
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  Serial.println("Display object created!");

  // Start display
  dma_display->begin();
  Serial.println("Display initialized!");

  // // Start at low brightness
  // dma_display->setBrightness8(40);

  // // Clear screen
  // dma_display->clearScreen();

  // Serial.println("Display initialized!");

}

void loop() {
  Serial.println("ESP32 is running...");
  delay(1000);

  // // RED
  // dma_display->fillScreen(
  //   dma_display->color565(255, 0, 0)
  // );
  // delay(2000);

  // // GREEN
  // dma_display->fillScreen(
  //   dma_display->color565(0, 255, 0)
  // );
  // delay(2000);

  // // BLUE
  // dma_display->fillScreen(
  //   dma_display->color565(0, 0, 255)
  // );
  // delay(2000);

  // // BLACK
  // dma_display->clearScreen();
  // delay(2000);
}

// put function definitions here:
