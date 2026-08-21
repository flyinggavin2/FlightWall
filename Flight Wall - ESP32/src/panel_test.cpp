//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 01_Showing_Text
//----------------------------------------Including the libraries.
#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
//----------------------------------------

//----------------------------------------Defines the connected PIN between P5 and ESP32.
#define R1_PIN 18
#define G1_PIN 8
#define B1_PIN 17
#define R2_PIN 16
#define G2_PIN 1
#define B2_PIN 15

#define A_PIN 7
#define B_PIN 48
#define C_PIN 6
#define D_PIN 47
#define E_PIN 2  //--> required for 1/32 scan panels, safe to leave defined

#define LAT_PIN 21
#define OE_PIN 4
#define CLK_PIN 5
//----------------------------------------

//----------------------------------------Defines the P5 Panel configuration.
#define PANEL_RES_X 128  // Width of each panel
#define PANEL_RES_Y 64  // Height of each panel
#define PANEL_CHAIN 1   // Number of chained panels
//----------------------------------------

// Initialize MatrixPanel_I2S_DMA as "dma_display".
MatrixPanel_I2S_DMA *dma_display = nullptr;

//----------------------------------------Variable for color.
uint16_t myBLACK = dma_display->color565(0, 0, 0);
uint16_t myWHITE = dma_display->color565(255, 255, 255);
uint16_t myRED = dma_display->color565(255, 0, 0);
uint16_t myGREEN = dma_display->color565(0, 255, 0);
uint16_t myBLUE = dma_display->color565(0, 0, 255);
//----------------------------------------

//________________________________________________________________________________VOID SETUP()
void setup() {
Serial.println("Starting Flight Wall display test...");
delay(1000);

// Initialize the connected PIN between Panel P5 and ESP32.
HUB75_I2S_CFG::i2s_pins _pins = {R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};
delay(10);

 Serial.println("Creating panel configuration...");
//----------------------------------------Module configuration.
HUB75_I2S_CFG mxconfig(
PANEL_RES_X,   //--> module width.
PANEL_RES_Y,   //--> module height.
PANEL_CHAIN,   //--> Chain length.
_pins          //--> pin mapping.
);
delay(10);

mxconfig.i2sspeed = HUB75_I2S_CFG::HZ_20M;  // I2S clock speed

// 👇👇👇 ADDED SCAN CONFIG HERE 👇👇👇
// mxconfig.scan = HUB75_I2S_CFG::SCAN_16;  // <-- Your panel is 1/16 scan
// 👆👆👆 ADDED SCAN CONFIG HERE 👆👆👆

//----------------------------------------Display Setup.
Serial.println("Creating display object...");
dma_display = new MatrixPanel_I2S_DMA(mxconfig);

 Serial.println("Starting display...");
dma_display->begin();
 Serial.println("Display initialized!");

dma_display->setBrightness8(155); // 0-255

dma_display->clearScreen();

dma_display->fillScreen(myWHITE);
delay(1000);
dma_display->fillScreen(myRED);
delay(1000);
dma_display->fillScreen(myGREEN);
delay(1000);
dma_display->fillScreen(myBLUE);
delay(1000);

dma_display->clearScreen();
delay(1000);
}
//________________________________________________________________________________

//________________________________________________________________________________VOID LOOP()
void loop() {
dma_display->setTextSize(1);

dma_display->setTextWrap(false);

dma_display->setCursor(10, 0);
dma_display->setTextColor(dma_display->color565(255, 153, 0));
dma_display->println("UTEH");

dma_display->setCursor(36, 0);
dma_display->setTextColor(dma_display->color565(255, 0, 255));
dma_display->print("STR");

dma_display->setCursor(11, 8);
dma_display->setTextColor(dma_display->color565(0, 152, 158));
dma_display->println("ARDUINO");

dma_display->setCursor(16, 17);
dma_display->setTextColor(dma_display->color565(255, 255, 255));
dma_display->print("P5");

dma_display->setCursor(30, 17);
dma_display->setTextColor(dma_display->color565(255, 0, 0));
dma_display->print("R");

dma_display->setTextColor(dma_display->color565(0, 255, 0));
dma_display->print("G");

dma_display->setTextColor(dma_display->color565(0, 0, 255));
dma_display->print("B");

dma_display->setCursor(16, 25);
dma_display->setTextColor(dma_display->color565(255, 0, 102));
dma_display->print("ESP");

dma_display->setCursor(36, 25);
dma_display->setTextColor(dma_display->color565(241, 197, 7));
dma_display->print("32");

delay(1000);
}
//________________________________________________________________________________
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<