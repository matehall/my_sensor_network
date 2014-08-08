// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _LCD_sensor_H_
#define _LCD_sensor_H_
#include "Arduino.h"
//add your includes for the project LCD_sensor here
#include <Sensor.h>

unsigned long SLEEP_TIME = 30; // Sleep time between reads (in seconds)

uint8_t my_radio_id = 10;
uint8_t dht_sensor_id = 23;
uint8_t pool_sensor_id = 24;

double pool_temp_1 = 0.0;
double pool_temp_2 = 0.0;

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project LCD_sensor here

void handleIncomingMessages(message_s);

//Do not add code below this line
#endif /* _LCD_sensor_H_ */
