file(GLOB cpp_files "cpp/*.cpp")
add_library(
    state STATIC 
    ${cpp_files}
)
target_include_directories(
    state INTERFACE 
    hpp
)
target_link_libraries(
    state
    SerialPort
)