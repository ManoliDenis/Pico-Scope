#ifndef SAMPLE_MANAGER_H_
#define SAMPLE_MANAGER_H_

/* INCLUDES */
#include "DataTransferObjects.h"


/* LIMITS */
#define NYQUIST_LIMIT 500000/2


/* PROBE CONFIGURATION */
#define USED_PROBE 1
#if USED_PROBE == 1
    #define PROBE_ADC_PIN 26
    #define PROBE_ADC_CHANNEL 0
#else
    #error "Unknown probe config. Please check probe config!"
#endif


/**
 * @file SampleManager.h
 * @author Br0k3 
 * @brief Manages sample logic
 */

// Sets up ADC and configures it for sampling
 StatusDTO sample_manager_init();

 StatusDTO sample_manager_start_sample();

#endif /* SAMPLE_MANAGER_H_ */