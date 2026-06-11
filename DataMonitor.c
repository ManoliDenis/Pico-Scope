#include "DataMonitor.h"
#include "hardware/adc.h"
#include "logger.h"
#include "ButtonManager.h"

uint16_t cpu_temp = 25;
uint32_t last_read= 0;


void setup_temperature() {
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
    LOG("Temp reader initialized.");
}

float get_temperature() {
    uint16_t raw = adc_read();
    float voltage = raw * 3.3f / 4096.0f;
    float temp_celsius = 27.0f - (voltage - 0.706f) / 0.001721f;
    
    return temp_celsius;
}

 void init_dependencies()
{
    setup_temperature();
    buttons_init();
}

void update_reads()
{   uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if(current_time - last_read >= READ_FREQUENCY)
    {
       cpu_temp = (uint16_t)(get_temperature()*100);

       last_read = current_time;
    }
}