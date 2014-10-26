#include <FastLED.h>
#define NUM_LEDS 25
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

byte redValue = 0;
byte blueValue = 0;
byte greenValue = 0;

unsigned long lastPrint = 0;

void setup() { 
	Serial.begin(115200);
	FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

}

void loop() { 
	checkSerial();
	updateStrip();

	// if(millis() - lastPrint > 1000){
	//     lastPrint = millis();
	//     printValues();
	// }
}

void updateStrip() {
	fill_solid(leds, NUM_LEDS, CRGB(redValue, greenValue, blueValue));
}

void checkSerial() {
	if(Serial.available() >= 2){
		byte firstByte = Serial.read();
		byte secondByte = Serial.read();

		if(firstByte != 0 && firstByte != 1 && firstByte != 2){
		    Serial.println("Invalid command.");
		}
		else{
			if(firstByte == 0){
				redValue = secondByte;
			}
			else if(firstByte == 1){
				greenValue = secondByte;
			}
			else if(firstByte == 2){
				blueValue = secondByte;
			}
		}
	}
}

void printValues(){
	String valueString = redValue + String(" ") + greenValue + String(" ") + blueValue;
	Serial.println(valueString);
}
