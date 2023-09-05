# CMake minimum version and project details
cmake_minimum_required(VERSION 3.10)
project(2D-zombie-shooter)


# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Source files
set(SOURCE_FILES
    src/main.cpp

    src/base/utils.cpp

    src/engine/CollisionManager.cpp

    src/game/core/Game.cpp
    src/game/core/Grid.cpp

    src/game/entities/Bullet.cpp
    src/game/entities/Entity.cpp
    src/game/entities/MovingEntity.cpp
    src/game/entities/Player.cpp
    src/game/entities/Wall.cpp
    src/game/entities/Zombie.cpp

    src/game/managers/BulletManager.cpp
    src/game/managers/WallManager.cpp
    src/game/managers/ZombieManager.cpp

    src/game/rendering/GameCamera.cpp
    src/game/rendering/Renderer.cpp

)


# Common Include directories
set(INCLUDE_DIRS
    src/3rdparty/raylib

    src/base

    src/engine

    src/game/core
    src/game/entities
    src/game/managers
    src/game/rendering
)

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)



################################ DEBUG ################################
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Create the executable from the sources files
    add_executable(debug ${SOURCE_FILES})

    # Indicate where are all the header files
    target_include_directories(debug PRIVATE ${INCLUDE_DIRS})

    # Link external libraries 
    target_link_directories(debug PRIVATE src/3rdparty/raylib) # Indicate where is the .a file of the libraries 
    target_link_libraries(debug PRIVATE raylib opengl32 gdi32 winmm) # Indicate which library we need

    # Add compilation options
    target_compile_options(debug PRIVATE -Wall -Wextra -g) # -g -> give informations to the debugger
endif()
########################################################################


################################ RELEASE ################################
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Create the executable from the sources files
    add_executable(release WIN32 ${SOURCE_FILES}) # WIN32 indicate that we are building an app with a ui, not a terminal app (it will not open the terminal )

    # Indicate where are all the header files
    target_include_directories(release PRIVATE ${INCLUDE_DIRS})

    # Link external libraries 
    target_link_directories(release PRIVATE src/3rdparty/raylib) # Indicate where is the .a file of the libraries 
    target_link_libraries(release PRIVATE raylib opengl32 gdi32 winmm) # Indicate which library we need

    # Add compilation options
    target_compile_options(release PRIVATE -O3) # Optimize the program (takes longer to compile but runs faster)

    # Add some dll files inside the executable
    target_link_options(release PRIVATE -static -static-libstdc++ -static-libgcc)
endif()
##########################################################################




###############
# Remove the command line when running the program
#set_target_properties(release PROPERTIES LINK_FLAGS "-mwindows")