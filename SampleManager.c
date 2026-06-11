#include "SampleManager.h"
#include "hardware/adc.h"

 StatusDTO sample_manager_init()
 {
   adc_init(); // Turn on ADC block
   adc_gpio_init(PROBE_ADC_PIN); // Configure GPIO for ADC use
   adc_select_input(PROBE_ADC_CHANNEL); // Select ADC channel to use
   adc_set_clkdiv(0); // Set ADC to default clock
   adc_fifo_setup(
        true,    // Write each completed conversion to the sample FIFO
        true,   // Don't assert the ERR bit on FIFO overflow
        1,       // Assert the IRQ flag when at least 1 sample is present
        false,   // We won't see the ERR bit because of the FIFO overflow policy above, so don't assert the IRQ flag on an error
        false    // Don't shift the result; we're only using 8 bits of precision in this example
    );
    return (StatusDTO){.complexity = STATUS_SIMPLE, .status.simple_status = {.status = STATUS_SUCCESS, .status_message = STATUS_SUCCESS_MESSAGE}};
 }
 StatusDTO sample_manager_start_sample()
 {
    adc_run(true); // Start the ADC
    return (StatusDTO){.complexity = STATUS_SIMPLE, .status.simple_status = {.status = STATUS_SUCCESS, .status_message = STATUS_SUCCESS_MESSAGE}};
 }
 #warning "Need to set custom frequencies ig"