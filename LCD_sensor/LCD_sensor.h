// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _DHT_sensor_H_
#define _DHT_sensor_H_
#include "Arduino.h"
//add your includes for the project DHT_sensor here
#include <Sensor.h>
unsigned long SLEEP_TIME = 30; // Sleep time between reads (in seconds)

uint8_t my_radio_id = 10;
uint8_t dht_sensor_id = 23;

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

void setRelayStatus(message_s);

//Do not add code below this line
#endif /* _DHT_sensor_H_ */
