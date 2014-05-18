// Do not remove the include below
#include "DHT_sensor.h"

void setup() {
	Serial.println("DHT-11 sensor starting up");
	dht.setup(HUMIDITY_SENSOR_DIGITAL_PIN);
	gw.begin(my_radio_id);
//
	// Send the Sketch Version Information to the Gateway
	gw.sendSketchInfo("DHT-11", "1.0");

//	// Register all sensors to gw (they will be created as child devices)
	gw.sendSensorPresentation(CHILD_ID_HUM, S_HUM);
	gw.sendSensorPresentation(CHILD_ID_TEMP, S_TEMP);
//
//	metric = gw.isMetricSystem();


}

void take_temp_reading() {
	float temperature = dht.getTemperature();
	if (isnan(temperature)) {
		Serial.println("Failed reading temperature from DHT");
		Serial.println(temperature);

	} else if (temperature != lastTemp) {
		lastTemp = temperature;

		gw.sendVariable(lcd_radio_id, CHILD_ID_TEMP, V_TEMP, temperature, 1);
		Serial.print("T: ");
		Serial.println(temperature);
	}
}

void take_humidity_reading() {
	float humidity = dht.getHumidity();
	if (isnan(humidity)) {
		Serial.println("Failed reading humidity from DHT");
	} else if (humidity != lastHum) {
		lastHum = humidity;
		gw.sendVariable(lcd_radio_id, CHILD_ID_HUM, V_HUM, humidity, 1);
		Serial.print("H: ");
		Serial.println(humidity);
	}
}

void power_down() {
	// Power down the radio.  Note that the radio will get powered back up
	// on the next write() call.
	Serial.println("DHT Powering down.");
	delay(1000); //delay to allow serial to fully print before sleep
	gw.powerDown();
	sleep.pwrDownMode(); //set sleep mode
	sleep.sleepDelay(SLEEP_TIME * 1000); //sleep for: sleepTime
	Serial.println("DHT is back!");
}

void loop() {
	Serial.println("reading");
	delay(dht.getMinimumSamplingPeriod());

	take_temp_reading();
	take_humidity_reading();
	
	//power_down();
}
