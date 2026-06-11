#ifndef RENDERMAP_H_
#define RENDERMAP_H_


#include "DataTransferObjects.h"
#include "pico/stdlib.h"
#include <stdio.h>


// For simpler points
typedef struct{
    uint8_t x;
    uint8_t y;
}POINT;


/* Inits render dependencies */
extern void render_map_init();
// Renders info 
void render_frame();
// Draws a box 
void draw_box(uint8_t xLow, uint8_t xMax, uint8_t yLow, uint8_t yMax);
//Clear buffer
void clear_buffer();
//Draws a pixel on the screen
void draw_pixel(uint8_t x, uint8_t y);
//Draws a character
void draw_character(const uint8_t character[],uint8_t x, uint8_t y, uint8_t scale);
//Draw line
void draw_line(POINT start, POINT target);

#endif /* RENDERMAP_H_ */