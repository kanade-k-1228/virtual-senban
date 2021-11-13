add_library(
    object STATIC 
    ./cpp/work.cpp
)
target_include_directories(
    object INTERFACE 
    ./hpp
)
target_link_libraries(
    object
    util
)