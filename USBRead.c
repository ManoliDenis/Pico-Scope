#include "USBRead.h"


uint8_t cub_x = 5;
uint8_t cub_y = 5;
uint8_t cub_size = 10;
uint8_t tboc = 0;
uint8_t cb = 0;
uint8_t log_state = 0;
uint8_t number = 0;
uint8_t tcb = 1;
 
uint32_t timp_ultima_citire = 0;

void process_usb_commands()
{
    uint32_t timp_curent = time_us_32();
    
    if (timp_curent - timp_ultima_citire > 50000) 
    {
        timp_ultima_citire = timp_curent;
        
        int input;
        while ((input = getchar_timeout_us(0)) != PICO_ERROR_TIMEOUT) 
        {
            switch (input) {
                case 'w': cub_y -= 2; break;
                case 's': cub_y += 2; break;
                case 'a': cub_x -= 2; break;
                case 'd': cub_x += 2; break;
                case '+': cub_size += 2; break;
                case '-': cub_size -= 2; break;
                case '1': if(tboc!=0)tboc=0; else tboc=1; break;
                case 'c': cb=1; break;
                case 'l': if(log_state!=0)log_state=0; else log_state=1; break;
                case 'n': ++number; number%=10; break;
                case 'b': --number; number%=10; break;
                case 't': if(tcb!=0)tcb=0; else tcb=1; break;
            }
        }
    }
}