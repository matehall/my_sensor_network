// Do not remove the include below
#include "LCD_sensor.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <SPI.h>
#include <EEPROM.h>
#include <RF24.h>

Sensor gw;

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
int i = 0;
int last_known_temp = 0;
int last_known_hum = 0;

void setup() {

	display.begin();
	display.display();
	display.clearDisplay();

	display.setContrast(50);
	display.setTextSize(1);
	display.setTextColor(BLACK);
	display.setCursor(0, 0);
	display.println("Starting LCD sensor noe v0.1:");
	Serial.print("Starting LCD sensor noe v0.1:");
	display.display();
	delay(2000);
	gw.begin(my_radio_id);
	gw.sendSketchInfo("LCD", "1.0");
	display.println("Registerd.");
	display.display();

//	gw.sendSensorPresentation(S_ARDUINO_NODE, 100);
}

void loop() {
	delay(SLEEP_TIME);
	Serial.print("Checking for measurement:");
	if (gw.messageAvailable()) {
		Serial.println("Measurement found:");
		message_s message = gw.getMessage();
		handleIncomingMessages(message);
	} else {
		Serial.println("NO measurement found:");
	}

}

void handleIncomingMessages(message_s message) {

	display.setContrast(50);
	display.setTextSize(1);
	display.setTextColor(BLACK);
	display.setCursor(0, 0);
	Serial.print("messageType:");
	Serial.println(message.header.messageType);

	if (message.header.messageType == M_SET_VARIABLE
			&& message.header.type == V_TEMP) {
		Serial.println("We have a temp:");
		int temperature = atoi(message.data);
		last_known_temp = temperature;
	}

	if (message.header.messageType == M_SET_VARIABLE
			&& message.header.type == V_HUM) {
		Serial.println("We have a hum:");
		int humidity = atoi(message.data);
		last_known_hum = humidity;

	}
	display.clearDisplay();
	display.print("T: ");
	display.println(last_known_temp);
	Serial.print("T:");
	Serial.println(last_known_temp);

	display.print("H: ");
	display.println(last_known_hum);

	Serial.print("H:");
	Serial.print(last_known_hum);
	display.display();
}
