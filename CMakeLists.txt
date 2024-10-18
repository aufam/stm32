cmake_minimum_required(VERSION 3.14)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    include("cmake/stm32-toolchain.cmake")
endif()

project(bluepill)

add_library(stm32 INTERFACE)

if (DEFINED F103_USE_CAN AND DEFINED F103_USE_USB)
    message(FATAL_ERROR "Since F103 can't use CAN and USB at the same time, we have to choose one")
elseif (DEFINED F103_USE_CAN)
    message(STATUS "STM32F103 using CAN")
    target_compile_definitions(stm32 INTERFACE F103_USE_CAN)
elseif (DEFINED F103_USE_USB)
    message(STATUS "STM32F103 using USB")
    target_compile_definitions(stm32 INTERFACE F103_USE_USB)
else ()
    message(FATAL_ERROR "You must define F103_USE_USB or F103_USE_CAN")
endif()

target_compile_definitions(stm32 INTERFACE 
	USE_HAL_DRIVER 
	STM32F103xB
)

target_compile_options(stm32 INTERFACE
    -mcpu=cortex-m3
    -mfloat-abi=soft
    $<$<COMPILE_LANGUAGE:C>:-Wno-strict-aliasing>
)

set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/STM32F103C8TX_FLASH.ld)
set(MAP ${PROJECT_BINARY_DIR}/stm32.map)

target_link_options(stm32 INTERFACE
    -mcpu=cortex-m3
    -specs=nano.specs
    -Wl,-gc-sections,--print-memory-usage,-Map=${MAP},--script=${LINKER_SCRIPT}
)

target_include_directories(stm32 INTERFACE
    Core/Inc
    Drivers/CMSIS/Device/ST/STM32F1xx/Include
    Drivers/CMSIS/Include
    Drivers/STM32F1xx_HAL_Driver/Inc
    Drivers/STM32F1xx_HAL_Driver/Inc/Legacy
    Middlewares/Third_Party/FreeRTOS/Source/include
    Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2
    Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3
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
    add_executable(bluepill.elf)

    target_link_libraries(bluepill.elf PRIVATE
        stm32
    )

    stm32_toolchain_post_build(bluepill)
endif()
