#include "Driver_SSD1306.h"


#define CONTROLLER_NAME "SSD1306"


// Possible controller addresses.Explained in detail in the datasheet of the controller.
#define ADDRESS_TYPE_1 0b0111100
#define ADDRESS_TYPE_2 0b0111101 


// Default Pins
#define SDA_PIN 16
#define SCL_PIN 17

// Screen size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


const uint8_t init_cmds[] = {
    0x00,       // START
    0xAE,       // Display OFF 
    0x20, 0x00, // Memory Addressing Mode:  HORIZONTAL
    0x21, 0x00, 0x7F, // Collumn limits: 0-127)
    0x22, 0x00, 0x07, // Page limits: 0-7)
    0x8D, 0x14, // Charge Pump ON (for pixels)
    0xAF        // Display ON 
};

uint8_t buffer[1024];
uint8_t payload[1025];


//Positions a pixel inside the buffer.Fixes positioning.Needs to be rendered to see
void draw_pixel(uint8_t x, uint8_t y)
{
    x = x%SCREEN_WIDTH;
    y = y%SCREEN_HEIGHT;

    uint16_t byte_index = x + (y / 8) * SCREEN_WIDTH;
    uint8_t bit_index = y % 8;

    buffer[byte_index] |= (1 << bit_index);

}

// Clears the buffer
void clear_buffer()
{
    for(int i=0; i<1024; ++i)
        buffer[i]=0;
}

//Initializes connection between the controller and pico
void render_map_init()
{
    //Init I2C
    i2c_init(i2c0,400*1000); // init i2c
    gpio_set_function(SDA_PIN,GPIO_FUNC_I2C); 
    gpio_set_function(SCL_PIN,GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);


    //Init Controller(SSD1306)
    payload[0] = 0x40;
    i2c_write_blocking(i2c0, ADDRESS_TYPE_1, init_cmds, sizeof(init_cmds), false);

}

// Renders the buffer on the actual screen
void render_frame()
{
    
    for(int i = 0; i < 1024; i++) {
        payload[i + 1] = buffer[i];
    }

    i2c_write_blocking(i2c0, ADDRESS_TYPE_1, payload, 1025, false);
}
