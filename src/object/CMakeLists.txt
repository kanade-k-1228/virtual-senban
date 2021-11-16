add_library(
    object STATIC 
    cpp/cylinder.cpp
    cpp/bite.cpp
)
target_include_directories(
    object INTERFACE 
    hpp
)
target_link_libraries(
    object
    util
)