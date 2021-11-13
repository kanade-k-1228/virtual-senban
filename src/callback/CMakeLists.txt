add_library(
    callback STATIC 
    ./cpp/initialize.cpp
    ./cpp/display.cpp 
    ./cpp/keyboard.cpp
    ./cpp/motion.cpp
    ./cpp/mouse.cpp 
    ./cpp/passive_motion.cpp 
    ./cpp/resize.cpp
)
target_include_directories(
    callback INTERFACE
    ./hpp
)
target_link_libraries(
    callback
    util object instance
)
