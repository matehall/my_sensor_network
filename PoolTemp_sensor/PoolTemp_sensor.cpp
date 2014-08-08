// Do not remove the include below
#include "PoolTemp_sensor.h"

void setup() {
	Serial.println("Pool sensor starting up");

	sensors.begin();
	gw.begin(my_radio_id);
//
	// Send the Sketch Version Information to the Gateway
	gw.sendSketchInfo("Pool", "1.0");
	numSensors = sensors.getDeviceCount();
	Serial.println("DS found: ");
	Serial.println(numSensors);
	// Register all sensors to gw (they will be created as child devices)
	for (int i = 0; i < numSensors && i < MAX_ATTACHED_DS18B20; i++) {
		gw.sendSensorPresentation(i, S_TEMP);
	}
	//metric = gw.isMetricSystem();
}

void loop() {
	Serial.println("Taking measurment.");
	sensors.requestTemperatures(); // Fetch temperatures from Dallas
	delay(100);
	for (int i = 0; i < numSensors && i < MAX_ATTACHED_DS18B20; i++) {
		// Fetch and round temperature to one decimal
		float temperature =
				static_cast<float>(static_cast<int>((
						metric ?
								sensors.getTempCByIndex(i) :
								sensors.getTempFByIndex(i)) * 10.)) / 10.;
		// Only send data if temperature has changed and no error
		Serial.println("Temp: ");
		Serial.println(temperature);
		if (lastTemperature[i] != temperature && temperature != -127.00) {
			//gw.powerUp(); // Powerup introduces a small delay (which is missing in radio.write powerup)
			// Send variable (using registered shortcut) to gw
			gw.sendVariable(lcd_radio_id,i, V_TEMP, temperature, 1);
			lastTemperature[i] = temperature;
		}
	}
	// Power down the radio.  Note that the radio will get powered back up
	// on the next write() call.
	delay(500);
//	gw.powerDown();
//	sleep.pwrDownMode(); //set sleep mode
//	sleep.sleepDelay(SLEEP_TIME * 1000); //sleep for: sleepTime
}
