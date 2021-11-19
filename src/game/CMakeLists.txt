file(GLOB src "src/*")
add_library(game STATIC ${src})
target_include_directories(game INTERFACE include)
target_link_libraries(game
    SerialPort
)