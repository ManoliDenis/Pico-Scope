#include "States.h"


short int current_state = 0; 
const unsigned int COLOR_COMBOS[NUM_STATES][LED_NUMBER] = {
    {1, 0, 0}, // RED
    {0, 1, 0}, // GREEN
    {0, 0, 1}, // BLUE
    {1, 1, 0}, // ORANGE
    {1 ,0 ,1}  // PINK
};
