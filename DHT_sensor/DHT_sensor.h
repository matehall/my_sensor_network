// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _DHT_sensor_H_
#define _DHT_sensor_H_
#include "Arduino.h"
//add your includes for the project DHT_sensor here
#include <Sleep_n0m1.h>
#include <SPI.h>
#include <EEPROM.h>
#include <RF24.h>
#include <Sensor.h>
#include <DHT.h>

#define CHILD_ID_HUM 0
#define CHILD_ID_TEMP 1
#define HUMIDITY_SENSOR_DIGITAL_PIN 3
unsigned long SLEEP_TIME = 60; // Sleep time between reads (in seconds)

Sensor gw;
DHT dht;
Sleep sleep;
float lastTemp;
float lastHum;
boolean metric = true;
uint8_t my_radio_id = 23;
uint8_t lcd_radio_id = 10;

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project DHT_sensor here

//Do not add code below this line
#endif /* _DHT_sensor_H_ */
