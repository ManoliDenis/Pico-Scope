#ifndef LAYER_UNIFIER_H_
#define LAYER_UNIFIER_H_


    
#include "SampleManager.h"
#include "TriggerSync.h"
#include "BufferManager.h"
#include "RenderMap.h"
#include "pico/stdlib.h"
#include "DataTransferObjects.h"
#include "logger.h"
#include "Guardian.h"
#include "States.h"
#include "USBRead.h"


/* DEFINES */
#define NUM_LAYERS 3


/* Initializes stdio and all layers
   HINT: Call before main loop */
 void layers_init_all();


/* Main loop logic. 
   HINT:Call inside main loop. */
 void main_loop_logic();

// DEV NOTES:

/**
 * @function: layers_init_all
 * @brief: inits stdio, inits all layers and for each layer checks if they have simple or complex DTOs and logs accoringly.
 */

#endif /* LAYER_UNIFIER_H_ */

