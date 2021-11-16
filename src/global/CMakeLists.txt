add_library(
    global STATIC 
    cpp/global.cpp
)
target_include_directories(
    global INTERFACE 
    hpp
)
target_link_libraries(
    global
    object
)
