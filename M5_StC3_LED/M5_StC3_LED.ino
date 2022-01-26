// ############################################
// Program:  M5_StC3_LED.ino
// Task:     Colorfull LED
// Autor:    R. Hoermann
// Version:  2022-01-26
// AddBoard: https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json
// Hardware: M5 Stamp C3
// IDEBoard: STAMP-C3
//
//      G0 G1 5V GND 5V 10 8  7  6  5  4 GND
//     +-o--o--o--o--o--o--o--o--o--o--o--o-+
//     |           M5 STAMP C3              |
//     |USBC                              Y |
//     |Power P2:WS12812 P3:Btn WiFi2.4GHz+ |
//     |Serial/Upload                       |
//     |                                    |
//     +-o--o--o--o--o--o--o--o--o--o-------+
//     GND 5V 19 18 GND 9  EN 20 21 3V3
//            D+  D-         ^Rx Txv
// ############################################
#include "Arduino.h"
#include <FastLED.h>

#define NUM_LEDS       1   // We have only ONE LED on Board
#define pin_WS2812     2   // GPIO Pin WS2812 LED is connected to
#define BRIGHTNESS    64   // 0..255
#define INTERVAL    1000   // Change Color every INTERVAL ms
CRGB ac_leds[NUM_LEDS];    // Define the array of leds

void setup()
{
	Serial.begin(115200); Serial.println();
	Serial.println("M5 Stamp C3 GRB-Demo");
	FastLED.addLeds<WS2812, pin_WS2812, RGB>(ac_leds, NUM_LEDS);  // GRB ordering is typical
}

void loop()
{
	for(uint8_t i=0;i<8;i++)
	{
		ac_leds[0]=0;
		if(i & 4) {ac_leds[0]+=BRIGHTNESS*0x10000;}
		if(i & 2) {ac_leds[0]+=BRIGHTNESS*  0x100;}
		if(i & 1) {ac_leds[0]+=BRIGHTNESS;        }
		Serial.printf("%d: %06X \r\n",i,ac_leds[0]);
		FastLED.show();  delay(INTERVAL);// Update the Color of the LED, then pause
	}
}
