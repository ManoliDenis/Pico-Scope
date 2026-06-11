#ifndef BUTTONMANAGER_H_
#define BUTTONMANAGER_H_

#include "pico/stdlib.h"

#define BUTTON_ONE 8
#define BUTTON_TWO 9
#define BUTTON_THREE 10
#define BUTTON_FOUR 11
#define BUTTON_FIVE 12
#define ANTI_BOUNCE_TIMEOUT 50

extern uint8_t button_states;

// All pins IN. PULL_UP.READ ON 0
void buttons_init();
// Clear buttons states
void btn_clear_garbage();


#endif