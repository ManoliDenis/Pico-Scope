
#include "LayerUnifier.h"
#include "hardware/watchdog.h"
#include "Characters.h"
#include "DataMonitor.h"
#include "Guardian.h"
#include "ButtonManager.h"


uint8_t SHOW_TEMP = true;



void state_5_callback(){cub_x = 5;cub_y=5;cub_size=10;button_states = button_states&(~5);};
void state_4_callback(){SHOW_TEMP=(SHOW_TEMP)?0:1; button_states = button_states&(~4);};
void state_3_callback(){};
void state_2_callback(){};
void state_1_callback(){};

void (*callback[5])(void) = {state_1_callback,state_2_callback,state_3_callback,state_4_callback,state_5_callback};

void button_on_layer(void (*callback[5])())
{   if(!callback){LOG("Wrong button_on_layer callbacks");return;}
    for(int i=1;i<=5;++i)
        if(button_states == i)
            callback[i-1]();              
}

void layers_init_all()
{
    stdio_init_all();
    StatusDTO (*status[NUM_LAYERS])(void) = {sample_manager_init, trigger_sync_init, buffer_manager_init};
    
    // Verifies every init 
    for(int i=0; i<NUM_LAYERS; ++i)
    {
        StatusDTO layer_status = status[i]();
        if( layer_status.complexity == STATUS_SIMPLE)
        {  
            if(layer_status.status.simple_status.status == STATUS_ERROR)
            {
                LOG("Failure on layer %d",i);
                LOG("Status message: %s", layer_status.status.simple_status.status_message);
            }
        }
        else if(layer_status.complexity == STATUS_COMPLEX)
        {
            if(layer_status.status.complex_status.status == STATUS_ERROR)
            {
                LOG("Failure on layer %d",i);
                LOG("Status message: %s", layer_status.status.complex_status.status_message);
                LOG("Stack trace: %s", layer_status.status.complex_status.stack_trace);
            }
        }

    }
    init_dependencies();
    guardian_monitor();
    render_map_init();
    
    current_state = STATE_IDLE; 
}


 void main_loop_logic()
 {
    LOG("Current state:%s Button states %d",(current_state==STATE_IDLE)?"STATE_IDLE":(current_state==STATE_DRAWING)?"STATE_DRAWING":(current_state==STATE_SAMPLING)?"STATE_SAMPLING":(current_state==STATE_WARNING)?"STATE_WARNING":(current_state==STATE_CRIITICAL_FAILURE)?"STATE_CRITICAL_FAILURE":"UNKNOWN",button_states);
    
    process_usb_commands();
    guardian_tick();
    button_on_layer(callback);
    if(_current_guardian_state == GUARDIAN_ONLINE)
        if(_current_guardian_status == GUARDIAN_STATUS_OK)
            goto STATE_MACHINE;
        else 
            goto SKIP;

    STATE_MACHINE:
    switch(current_state)
        {
            case STATE_IDLE:
                current_state = STATE_DRAWING;
            break;

            case STATE_SAMPLING:
                sample_manager_start_sample();
            break;
            case STATE_DRAWING:

                // toggle clear buffer
                if(tcb)clear_buffer();
                
                // toogle unit LOG ON/OFF
                if(log_state)LOG("X: %d Y: %d  S: %d  C:%d", cub_x,cub_y,cub_size,number);

                // clear buffer
                if(cb){clear_buffer();cb=0;};
                
                // moving unit
                if(!tboc)
                    draw_box(cub_x,cub_x+cub_size,cub_y,cub_y+cub_size);
                else
                    draw_character(NUMBER(number),cub_x,cub_y,cub_size);
                

                // temp debug
                if(SHOW_TEMP)
                {
                    draw_character(LETTER('T'),60,53,2);
                    draw_box(71,73,61,63);
                    draw_box(71,73,55,57);
                    draw_character(NUMBER(cpu_temp/1000),78,53,2);
                    draw_character(NUMBER(cpu_temp/100%10),90,53,2);
                    draw_box(101,103,61,63);
                    draw_character(NUMBER(cpu_temp/10%10),105,53,2);
                    draw_character(NUMBER(cpu_temp%10),117,53,2);
                }

                // draw on display
                render_frame();
            break;
            case STATE_WARNING:

            break;
            case STATE_CRIITICAL_FAILURE:

            break;

            default: //Safety reset
                watchdog_reboot(0,SRAM_END,0);
            break;
        }
    
    SKIP:
 
}
