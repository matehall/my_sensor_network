// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _PoolTemp_sensor_H_
#define _PoolTemp_sensor_H_
#include "Arduino.h"
//add your includes for the project PoolTemp_sensor here
#include "Sleep_n0m1.h"
#include "SPI.h"
#include "EEPROM.h"
#include "Sensor.h"
#include "RF24.h"
#include "OneWire.h"
#include "DallasTemperature.h"

#define ONE_WIRE_BUS 3
#define MAX_ATTACHED_DS18B20 16

unsigned long SLEEP_TIME = 60;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
Sensor gw;
Sleep sleep;

float lastTemperature[MAX_ATTACHED_DS18B20];
int numSensors = 0;
boolean metric = true;

uint8_t my_radio_id = 24;
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

//add your function definitions for the project PoolTemp_sensor here




//Do not add code below this line
#endif /* _PoolTemp_sensor_H_ */
