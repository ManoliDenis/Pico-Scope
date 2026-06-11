#ifndef DATAMONITOR_H_
#define DATAMONITOR_H_
#include "pico/stdlib.h"
/** @file DataMonitor.h
 * @author Br0k3 
 * @brief Contains the most crucial data that needs to be monitored.
 */

#define READ_FREQUENCY 250

extern uint16_t cpu_temp;
extern uint32_t last_read;
extern uint8_t button_states;

void init_dependencies();
void update_reads();

#endif /* DATAMONITOR_H_ */