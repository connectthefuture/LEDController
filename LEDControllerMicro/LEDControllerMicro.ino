#include <FastLED.h>
#define NUM_LEDS 150
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

byte redValue = 0;
byte blueValue = 0;
byte greenValue = 0;
byte maxLEDs = 50;

unsigned long lastPrint = 0;

void setup() { 
	Serial.begin(115200);
	FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
	digitalWrite(13, HIGH);
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
	// for(int i=0; i<NUM_LEDS; i++){
	//     leds[i].setRGB(redValue, greenValue, blueValue);
	// }
	FastLED.clear();
	fill_solid(&(leds[0]), maxLEDs, CRGB(redValue, greenValue, blueValue));
	FastLED.show();
}

void checkSerial() {
	if(Serial.available() >= 2){
		byte firstByte = Serial.read();
		byte secondByte = Serial.read();

		if(firstByte != 0 && firstByte != 1 && firstByte != 2 && firstByte != 3){
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
			else if(firstByte == 3){
				maxLEDs = secondByte;
			}
		}
	}
}

void printValues(){
	String valueString = redValue + String(" ") + greenValue + String(" ") + blueValue;
	Serial.println(valueString);
}
