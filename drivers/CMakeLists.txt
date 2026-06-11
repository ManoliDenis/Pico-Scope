add_library(hardware_drivers
    Driver_SSD1306.c
)

target_include_directories(hardware_drivers PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(hardware_drivers PUBLIC
    hardware_i2c
    pico_stdlib
)