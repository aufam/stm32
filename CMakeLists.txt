cmake_minimum_required(VERSION 3.16)

# project settings
project(stm32 C CXX ASM)

# source files
file(GLOB_RECURSE SOURCES 
    Core/*.*
    Middlewares/ST/*.*
    Middlewares/Third_Party/FreeRTOS/*.*
    Drivers/*.*
    USB_DEVICE/*.*
)

add_library(stm32 ${SOURCES} ${LINKER_SCRIPT})

# defines
target_compile_definitions(stm32 PUBLIC -DUSE_HAL_DRIVER -DSTM32F411xE)

# include directories
target_include_directories(stm32 PUBLIC
    Core/Inc 
    Drivers/CMSIS/Device/ST/STM32F4xx/Include 
    Drivers/CMSIS/Include
    Drivers/STM32F4xx_HAL_Driver/Inc 
    Drivers/STM32F4xx_HAL_Driver/Inc/Legacy 
    Middlewares/Third_Party/FreeRTOS/Source/include 
    Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 
    Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F 
    Middlewares/ST/STM32_USB_Device_Library/Core/Inc 
    Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc 
    USB_DEVICE/App 
    USB_DEVICE/Target 
)

# enable assembler files preprocessing
target_compile_options(stm32 PUBLIC
    $<$<COMPILE_LANGUAGE:ASM>:-x$<SEMICOLON>assembler-with-cpp>
)

# optimization flags
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    target_compile_options(stm32 PUBLIC -Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    target_compile_options(stm32 PUBLIC -Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
else ()
    message(STATUS "Minimal optimization, debug info included")
    target_compile_options(stm32 PUBLIC -Og -g)
endif ()

target_compile_options(stm32 PUBLIC
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-permissive>
)

# garbage collection
target_compile_options(stm32 PUBLIC -ffunction-sections -fdata-sections -fno-common)
target_link_options(stm32 PUBLIC -ffunction-sections -fdata-sections -fno-common)

# hardware floating point
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
target_compile_options(stm32 PUBLIC -mfloat-abi=hard -mfpu=fpv4-sp-d16)
target_link_options(stm32 PUBLIC -mfloat-abi=hard -mfpu=fpv4-sp-d16)

# cpu
target_compile_options(stm32 PUBLIC -mcpu=cortex-m4 -mthumb -mthumb-interwork)
target_link_options(stm32 PUBLIC -mcpu=cortex-m4 -mthumb -mthumb-interwork)

# warnings
target_compile_options(stm32 PUBLIC
    -Wall
    -Wextra
    $<$<COMPILE_LANGUAGE:C>:-Wno-unused-parameter>
    $<$<COMPILE_LANGUAGE:CXX>:-Wno-literal-suffix>
    $<$<COMPILE_LANGUAGE:CXX>:-Wno-attributes>
)

# library
target_link_options(stm32 PUBLIC -specs=nano.specs -lm -lc)

# linker script
set(LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/STM32F411CEUX_FLASH.ld)
set(MAP ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
target_link_options(stm32 PUBLIC -Wl,-gc-sections,--print-memory-usage,-Map=${MAP},--script=${LINKER_SCRIPT})

