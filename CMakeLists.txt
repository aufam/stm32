cmake_minimum_required(VERSION 3.14)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    include("cmake/stm32-toolchain.cmake")
endif()

project(devebox)

add_library(stm32 INTERFACE)

target_compile_definitions(stm32 INTERFACE
	USE_HAL_DRIVER
	STM32F407xx
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

set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/STM32F407VGTX_FLASH.ld)
set(MAP ${PROJECT_BINARY_DIR}/stm32.map)

target_link_options(stm32 INTERFACE
    -mcpu=cortex-m4
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -u _printf_float
    -specs=nano.specs
    -Wl,-gc-sections,--print-memory-usage,-Map=${MAP},--script=${LINKER_SCRIPT}
)

target_include_directories(stm32 INTERFACE
    Core/Inc
    Drivers/CMSIS/Include
    Drivers/CMSIS/Device/ST/STM32F4xx/Include 
    Drivers/STM32F4xx_HAL_Driver/Inc 
    Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
    Middlewares/Third_Party/FreeRTOS/Source/include
    Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2
    Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
    Middlewares/Third_Party/FatFs/src
    Middlewares/ST/STM32_USB_Device_Library/Core/Inc
    Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
    FATFS/App
    FATFS/Target
    USB_DEVICE/App
    USB_DEVICE/Target
)

file(GLOB_RECURSE SOURCES
    Core/*.*
    Middlewares/ST/*.*
    Middlewares/Third_Party/FreeRTOS/*.*
    Middlewares/Third_Party/FatFs/*.*
    Drivers/*.*
    FATFS/*.*
    USB_DEVICE/*.*
    Project/*.*
)

target_sources(stm32 INTERFACE ${SOURCES})

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_executable(devebox.elf)

    target_link_libraries(devebox.elf PRIVATE
        stm32
    )

    stm32_toolchain_post_build(devebox)
endif()
