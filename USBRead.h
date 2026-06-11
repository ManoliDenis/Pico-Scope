#ifndef USBREAD_H_
#define USBREAD_H_

#include "pico/stdlib.h"
#include <stdio.h>

extern uint8_t cub_x;
extern uint8_t cub_y;
extern uint8_t cub_size;
extern uint8_t tboc; //Block or character
extern uint8_t cb; //Clear buffer (manual)
extern uint8_t log_state; //Toggle Positional LOGGING ON/OFF
extern uint8_t number; // Selected Character Number
extern uint8_t tcb; //Toggle Clear Buffer
//Read usb data
void process_usb_commands();

#endif