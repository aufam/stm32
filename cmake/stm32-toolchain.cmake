set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_COMPILER    "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER  "arm-none-eabi-g++")
set(CMAKE_ASM_COMPILER  "arm-none-eabi-gcc")
set(CMAKE_AR            "arm-none-eabi-ar")
set(CMAKE_OBJCOPY       "arm-none-eabi-objcopy")
set(CMAKE_OBJDUMP       "arm-none-eabi-objdump")
set(CMAKE_C_LINKER      "arm-none-eabi-ld")
set(CMAKE_CXX_LINKER    "arm-none-eabi-ld")
set(CMAKE_SIZE          "arm-none-eabi-size")

enable_language(C CXX ASM)

add_compile_options(
    $<$<COMPILE_LANGUAGE:ASM>:-x$<SEMICOLON>assembler-with-cpp>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fpermissive>
)

function(stm32_toolchain_post_build name)
    set(HEX_FILE ${PROJECT_BINARY_DIR}/${name}.hex)
    set(BIN_FILE ${PROJECT_BINARY_DIR}/${name}.bin)
    add_custom_command(
        TARGET ${name}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex ${name}.elf ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary ${name}.elf ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}\nBuilding ${BIN_FILE}"
    )

    add_custom_target(flash
        COMMAND st-flash write ${BIN_FILE} 0x08000000
        DEPENDS ${BIN_FILE}
    )

    add_custom_target(dfu
        COMMAND dfu-util -a 0 -D ${BIN_FILE} -s 0x08000000:leave
        DEPENDS ${BIN_FILE}
    )
endfunction()
