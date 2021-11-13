add_library(
    instance STATIC 
    ./cpp/instance.cpp
)
target_include_directories(
    instance INTERFACE 
    ./hpp
)
target_link_libraries(
    instance
    object
)
