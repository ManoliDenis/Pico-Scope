

#include "LayerUnifier.h"
#include <stdio.h>
int main(void)
{
    layers_init_all(); // Init all
    
    while(1)
        main_loop_logic(); // Loop
    
}
