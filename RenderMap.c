
#include "RenderMap.h"
#include "Characters.h"
#include "logger.h"
#include <stdlib.h>
#include "GLOBALS.h"
#include "Driver_SSD1306.h"

#define RENDER_LOCAL_DEBUG 0
#if RENDER_LOCAL_DEBUG == 0 
    #define LOG(...) 0;
#endif

#define ADDRESS_TYPE_1 0b0111100
#define ADDRESS_TYPE_2 0b0111101

//Graph
#define GRAPH_MIN_X 2
#define GRAPH_MAX_X 126
#define GRAPH_MIN_Y 10
#define GRAPH_MAX_Y 50

static uint32_t GRAPH_UNIT_T = 1; // for time
static uint32_t GRAPH_UNIT_V = 1; // for current



// Draw line Bresenham
void draw_line(POINT start, POINT target)
{ 
    int dx = abs(target.x - start.x);
    int dy = abs(target.y - start.y);
    int sx = (start.x < target.x) ? 1 : -1;
    int sy = (start.y < target.y) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        draw_pixel(start.x, start.y);
        if (start.x == target.x && start.y == target.y) break;

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; start.x += sx; }
        if (e2 <  dx) { err += dx; start.y += sy; }
    }
}

static const uint8_t MASK_5B5[] =
{
    0,0,1,0,0,
    0,1,1,1,0,
    1,1,1,1,1,
    0,1,1,1,0,
    0,0,1,0,0

};

void stretch(const uint8_t character[], uint8_t *reference, uint8_t scale, uint8_t char_size_x, uint8_t char_size_y)
{
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            if (character[r * 5 + c] == 1) {
                reference[(c * scale) * char_size_y + (r * scale)] = 2;
            }
        }
    }
}

void fill(uint8_t *reference, uint8_t char_size_x, uint8_t char_size_y)
{
    uint8_t scale = char_size_x / 5;
    
    for (int u = 0; u < char_size_x; ++u) {
        for (int t = 0; t < char_size_y; ++t) {
            if (reference[u * char_size_y + t] == 2) {
                for (int i = 0; i < scale; ++i) {
                    for (int j = 0; j < scale; ++j) {
                        if ((u + i) < char_size_x && (t + j) < char_size_y) {
                            reference[(u + i) * char_size_y + (t + j)] = 1;
                        }
                    }
                }
            }
        }
    }
}

void scale_image(const uint8_t character[], uint8_t scale, uint8_t *char_size_x, uint8_t *char_size_y)
{
    *char_size_x = scale * CHAR_SIZE_X;
    *char_size_y = scale * CHAR_SIZE_Y;

    for(int i = 0; i < (*char_size_x * *char_size_y); i++) {
        memory_block1[i] = 0;
    }

    stretch(character, memory_block1, scale, *char_size_x, *char_size_y);
    fill(memory_block1, *char_size_x, *char_size_y);
}



void draw_box(uint8_t xLow, uint8_t xMax, uint8_t yLow, uint8_t yMax)
{
    for(uint8_t u = xLow ; u < xMax ; ++u)
        for(uint8_t t = yLow ; t < yMax ; ++t) 
            draw_pixel(u, t);  
}

void draw_character(const uint8_t character[], uint8_t x, uint8_t y, uint8_t scale)
{
    uint8_t x_fin;
    uint8_t y_fin;
    
    LOG("Scaling...");
    scale_image(character, scale, &x_fin, &y_fin);
    LOG("Acknowledged!");

    LOG("Starting Drawing..");
    for(int u = 0 ; u < x_fin ; ++u)
        for(int t = 0 ; t < y_fin ; ++t){
            LOG("Drawing pixel (%d,%d)", x+u, y+t);
            (memory_block1[u * y_fin + t]) ? draw_pixel(x+u, y+t) : 0;
            LOG("Drawing ACK");
        }
}


