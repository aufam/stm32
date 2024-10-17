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

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F103C8TX_FLASH.ld)
add_library(stm32 ${SOURCES} ${LINKER_SCRIPT})

if (DEFINED F103_USE_CAN AND DEFINED F103_USE_USB)
    message(FATAL_ERROR "Since F103 can't use CAN and USB at the same time, we have to choose one")
elseif (DEFINED F103_USE_CAN)
    message(STATUS "Using CAN")
    target_compile_definitions(stm32 PUBLIC F103_USE_CAN)
elseif (DEFINED F103_USE_USB)
    message(STATUS "Using USB")
    target_compile_definitions(stm32 PUBLIC F103_USE_USB)
else ()
    message(FATAL_ERROR "You must define F103_USE_USB or DF103_USE_CAN")
endif()

# include
target_include_directories(stm32 PUBLIC
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

# defines
target_compile_definitions(stm32 PUBLIC
    STM32F103xB
    USE_HAL_DRIVER
)

# compile options
target_compile_options(stm32 PRIVATE
    -Wall
    -Wextra
    -Wundef
    -Wno-double-promotion
    $<$<COMPILE_LANGUAGE:C>:-Wno-unused-parameter>
    $<$<COMPILE_LANGUAGE:CXX>:-Wno-literal-suffix>
    $<$<COMPILE_LANGUAGE:CXX>:-Wno-attributes>
)

# link options
target_link_options(stm32
    -specs=nano.specs
    -Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map,--script=${LINKER_SCRIPT}
)

