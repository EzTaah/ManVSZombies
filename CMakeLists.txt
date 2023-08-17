cmake_minimum_required(VERSION 3.10)

# Project name
project(ManVsZombie)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories, CMake will inform the compiler to also look in this directory when resolving #include directives.
include_directories(src)
include_directories(lib/raylib)
include_directories(src/core)    
include_directories(src/entities/include)
include_directories(src/managers/include)
include_directories(src/utilities)
include_directories(src/rendering/include)

# Link directories (where the .a or .lib files are located)
link_directories(lib/raylib)

# source -> ancien
# Source files
set(SOURCE_FILES
    src/main.cpp

    src/core/game.hpp
    src/core/game.cpp

    src/entities/include/bullet.hpp
    src/entities/src/bullet.cpp
    src/entities/include/player.hpp
    src/entities/src/player.cpp
    src/entities/include/wall.hpp
    src/entities/src/wall.cpp
    src/entities/include/zombie.hpp
    src/entities/src/zombie.cpp

    src/managers/include/bullet_manager.hpp
    src/managers/src/bullet_manager.cpp
    src/managers/include/collision_manager.hpp
    src/managers/src/collision_manager.cpp
    src/managers/include/grid_manager.hpp
    src/managers/src/grid_manager.cpp
    src/managers/include/input_manager.hpp
    src/managers/src/input_manager.cpp
    src/managers/include/wall_manager.hpp
    src/managers/src/wall_manager.cpp
    src/managers/include/zombie_manager.hpp
    src/managers/src/zombie_manager.cpp

    src/rendering/include/renderer.hpp
    src/rendering/src/renderer.cpp
    src/rendering/include/game_camera.hpp
    src/rendering/src/game_camera.cpp

    src/utilities/library.hpp
    src/utilities/library.cpp
)

# Set the location of the exe file that will be created
add_executable(debug ${SOURCE_FILES})     # <- this is the target

# include -> ancien

# Link to all the needed library
target_link_libraries(debug raylib opengl32 gdi32 winmm)

# compiler linker flags 
target_compile_options(debug PRIVATE -Wall -Wextra)