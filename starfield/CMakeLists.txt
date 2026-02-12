project(starfield C CXX ASM)

add_executable(starfield main.cpp)

pico_set_program_name(starfield "starfield")
pico_set_program_version(starfield "0.1")

pico_enable_stdio_uart(starfield 0)
pico_enable_stdio_usb(starfield 1)

target_link_libraries(starfield
        pico_stdlib
        hardware_spi
        displaylib_16)

target_include_directories(starfield PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ../displaylib_16bit_PICO/include)

pico_add_extra_outputs(starfield)