#ifndef DRIVER_SSD1306_H_
#define DRIVER_SSD1306_H_

/** This library specializes in drawing with an SSD1306 module */
/**  Q:Why i did it?  A: To add an extra layer between software and hardware*/

/* INCLUSIONS */
#include "pico/stdlib.h"
#include "hardware/i2c.h"



/* FUNCTIONS */

//Draws a pixel on the screen
void draw_pixel(uint8_t x, uint8_t y);

#endif