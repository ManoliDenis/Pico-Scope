#ifndef STATES_H_
#define STATES_H_

extern short int current_state; 


/* DEFINES */

#define LED_NUMBER 3
#define NUM_STATES 4
#define GET_STATE() current_state
#define SET_STATE(STATE) do { \
    if(STATE >= -1 && STATE < NUM_STATES) { \
        current_state = STATE; \
    } else { \
        LOG("Invalid state") \
    } \
} while(0)


// System states. Used for debbuging
typedef enum 
{
   STATE_CRIITICAL_FAILURE = -1, //  COLOR: RED
   STATE_IDLE = 0, // COLOR: GREEN
   STATE_SAMPLING = 1, // COLOR: BLUE
   STATE_DRAWING = 2, // COLOR: PINK
   STATE_WARNING = 3, //COLOR: ORANGE

} SYSTEM_STATE;

// Color manifesto. Enum storing LED states.
typedef enum {
    COLOR_RED = 0,
    COLOR_GREEN = 1,
    COLOR_BLUE = 2,
    COLOR_ORANGE = 3,
    COLOR_PINK = 4

} COLOR_MANIFESTO;



// Color combinations matching the states.
extern const unsigned int COLOR_COMBOS[NUM_STATES][LED_NUMBER];
#endif /* STATES_H_ */