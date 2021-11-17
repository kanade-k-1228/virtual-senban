file(GLOB cpp_files "cpp/*.cpp")
add_library(
    state STATIC 
    ${cpp_files}
)
target_include_directories(
    state INTERFACE 
    hpp
)
