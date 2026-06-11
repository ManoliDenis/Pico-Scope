#ifndef LOGGER_H_
#define LOGGER_H_

/** @brief LOGGER.H is a library containing a lot of methods for logging  */

#if __has_include(<cstdarg>)
    #include <cstdarg>
#elif __has_include(<stdarg.h>)
    #include <stdarg.h>
#endif

#define DEBUG 1
#define LOG_FREQUENCY 500


#if __has_include(<stdio.h>)// C 
    #include <stdio.h> 
    #include "pico/stdlib.h"
    #define SELECTED_OUTPUT stdout
        #define print(x,...) fprintf(SELECTED_OUTPUT,x, ##__VA_ARGS__)
#else // ERROR
    /** TODO: IMPLEMENT OTHER OUTPUTS OPTIONAL */
    #error "Not yet implemented!"
#endif

inline unsigned int GetMessageLength(const char *message)
{
    if(message == 0) return 0;
    unsigned int counter = 0;
    while(*message != '\0')
        ++counter,++message;
    return counter;
}

// Lower LOG Frequency
static inline uint8_t log_throttle() {
    static uint32_t last_log_time = 0; 
    
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    uint8_t verdict = 0;

    if (current_time - last_log_time >= LOG_FREQUENCY) {
        
        verdict = 0xFF;
        
        last_log_time = current_time; 
    }
    return verdict;
}

 //Logger
#define LOG_DEBUG(message, ...) do { \
    if (message != 0 && log_throttle()) { \
        print("[DEBUG]: "); \
        print(message, ##__VA_ARGS__); \
        print("\n"); \
    } \
} while(0)

#if DEBUG == 1 && __has_include("logger.h")
    #include "logger.h"
    #define LOG(x,...) LOG_DEBUG(x, ##__VA_ARGS__)
#else
    #warning "LOG NOT ACTIVE"
    #define LOG(x,...) ((void)0)
#endif

#endif
