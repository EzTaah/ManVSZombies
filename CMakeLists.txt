cmake_minimum_required(VERSION 3.10)

# Project name
project(ManVsZombie)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories, CMake will inform the compiler to also look in this directory when resolving #include directives.
include_directories(source)
include_directories(lib/raylib)
include_directories(source/core)    
include_directories(source/entities/include)
include_directories(source/utilities)

# Link directories (where the .a or .lib files are located)
link_directories(lib/raylib)

# Source files
set(SOURCE_FILES
    source/main.cpp

    source/core/game.hpp
    source/core/game.cpp

    source/entities/include/bullet.hpp
    source/entities/src/bullet.cpp
    source/entities/include/bullets.hpp
    source/entities/src/bullets.cpp
    source/entities/include/enemies.hpp
    source/entities/src/enemies.cpp
    source/entities/include/enemy.hpp
    source/entities/src/enemy.cpp
    source/entities/include/entity.hpp
    source/entities/src/entity.cpp
    source/entities/include/player.hpp
    source/entities/src/player.cpp

    source/utilities/library.hpp
    source/utilities/library.cpp
)

# Set the location of the exe file that will be created
add_executable(debug ${SOURCE_FILES})     # <- this is the target

# Link to all the needed library
target_link_libraries(debug raylib opengl32 gdi32 winmm)

# compiler linker flags 
target_compile_options(debug PRIVATE -Wall -Wextra)