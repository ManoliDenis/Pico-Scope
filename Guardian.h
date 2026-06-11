#ifndef GURADIAN_H_
#define GURADIAN_H_

/* Includes */
/* NOTE: The most important tools for fixers */
#include "logger.h"
#include "DataTransferObjects.h"
#include "DataMonitor.h"


/** @file Guardian.h
 * @author Br0k3 
 * @brief Monitors and protects the system from taking damage by monitoring and acting accordingly
 */

// State of the guardian, whether it's awake or sleeping
typedef enum {
    GUARDIAN_ONLINE,
    GUARDIAN_OFFLINE
} GuardianState;

// System state 
typedef enum {
    GUARDIAN_STATUS_OK,
    GUARDIAN_STATUS_ERROR
} GuardianStatus;


extern GuardianStatus _current_guardian_status;
extern GuardianState _current_guardian_state;

/* Monitors and protects the system. Works as a toggle button.Read the state from current_guardian_state */
void guardian_monitor();

// Guards
void guardian_tick();


/*  DEV NOTE:
    The guardian should serve as an indicator and a protector for the system. If it encounters an error, the program should stop running and ask for 
    the help of a fixer that will read the log files from the terminal.
*/

#endif /* GURADIAN_H_ */