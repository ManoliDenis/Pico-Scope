#include "ButtonManager.h"
#include "DataMonitor.h"

uint8_t button_states;
static uint32_t last_press_times[13] = {0}; 
void GLOBAL_CALLBACK(uint gpio, uint32_t events)
{
    uint32_t current_time = to_ms_since_boot(get_absolute_time());

    // Debounce de 50ms pentru fiecare pin independent
    if (current_time - last_press_times[gpio] >= ANTI_BOUNCE_TIMEOUT)
    {
        last_press_times[gpio] = current_time;

        switch(gpio)
        {
            case BUTTON_ONE:
                button_states |= 0x1;
                break;
            case BUTTON_TWO:
                button_states |= 0x2;
                break;
            case BUTTON_THREE:
                button_states |= 0x3;
                break;
            case BUTTON_FOUR:
                button_states |= 0x4;
                break;
            case BUTTON_FIVE:
                button_states |= 0x5;
                break;
            default:
                break;
        }
    }
}

void buttons_init()
{
    
    for(uint8_t pin=8;pin <= 12; ++ pin)
    {
        gpio_init(pin);
        gpio_set_dir(pin,GPIO_IN);
        gpio_pull_up(pin);
    }
    gpio_set_irq_enabled_with_callback(BUTTON_ONE,GPIO_IRQ_EDGE_FALL,true,&GLOBAL_CALLBACK);
    gpio_set_irq_enabled(BUTTON_TWO,GPIO_IRQ_EDGE_RISE,true);
    gpio_set_irq_enabled(BUTTON_THREE,GPIO_IRQ_EDGE_RISE,true);
    gpio_set_irq_enabled(BUTTON_FOUR,GPIO_IRQ_EDGE_RISE,true);
    gpio_set_irq_enabled(BUTTON_FIVE,GPIO_IRQ_EDGE_RISE,true);
}

void btn_clear_garbage()
{
    button_states = 0;
}