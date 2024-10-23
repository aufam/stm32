cmake_minimum_required(VERSION 3.16)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    include("cmake/stm32-toolchain.cmake")
endif()

project(blackpill)

add_library(stm32 INTERFACE)

target_compile_definitions(stm32 INTERFACE
	USE_HAL_DRIVER
    STM32F411xE	
)

target_compile_options(stm32 INTERFACE
    -mcpu=cortex-m4
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -mthumb
    -ffunction-sections
    -fdata-sections
    -fno-common
    $<$<COMPILE_LANGUAGE:C>:-Wno-strict-aliasing>
    $<$<COMPILE_LANGUAGE:C>:-Wno-unused-parameter>
)

set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/STM32F411CEUX_FLASH.ld)
set(MAP ${PROJECT_BINARY_DIR}/stm32.map)

target_link_options(stm32 INTERFACE
    -mcpu=cortex-m4
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -u _printf_float
    -specs=nano.specs
    -Wl,-gc-sections,--print-memory-usage,-Map=${MAP},--script=${LINKER_SCRIPT}
)

# include directories
target_include_directories(stm32 INTERFACE
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

file(GLOB_RECURSE SOURCES
    Core/*.*
    Middlewares/ST/*.*
    Middlewares/Third_Party/FreeRTOS/*.*
    Drivers/*.*
    USB_DEVICE/*.*
)

target_sources(stm32 INTERFACE ${SOURCES})

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_executable(blackpill.elf)

    target_link_libraries(blackpill.elf PRIVATE
        stm32
    )

    stm32_toolchain_post_build(blackpill)
endif()
