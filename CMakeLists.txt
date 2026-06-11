# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Osciloscop_Pico C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Osciloscop_Pico 
    Osciloscop_Pico.c
    SampleManager.c
    TriggerSync.c
    BufferManager.c
    RenderMap.c
    Guardian.c
    LayerUnifier.c
    States.c
    USBRead.c
    Characters.c
    GLOBALS.c
    DataMonitor.c
    ButtonManager.c
    )

pico_set_program_name(Osciloscop_Pico "Osciloscop_Pico")
pico_set_program_version(Osciloscop_Pico "0.1")

# Generate PIO header
pico_generate_pio_header(Osciloscop_Pico ${CMAKE_CURRENT_LIST_DIR}/blink.pio)

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Osciloscop_Pico 0)
pico_enable_stdio_usb(Osciloscop_Pico 1)

# Add the standard library to the build
target_link_libraries(Osciloscop_Pico
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(Osciloscop_Pico PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/inc
)

# Add drivers
add_subdirectory(drivers)

# Add any user requested libraries
target_link_libraries(Osciloscop_Pico 
        hardware_i2c
        hardware_dma
        hardware_pio
        hardware_interp
        hardware_timer
        hardware_clocks
        hardware_adc
        hardware_drivers
        )

pico_add_extra_outputs(Osciloscop_Pico)

