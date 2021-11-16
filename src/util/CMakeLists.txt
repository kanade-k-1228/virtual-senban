add_library(
    util STATIC 
    cpp/mouse_mapping.cpp
)
target_include_directories(
    util INTERFACE 
    hpp
)
