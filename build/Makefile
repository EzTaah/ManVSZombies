default:
	g++ -std=c++23 ../src/*.cpp -o debug.exe -O2 -Wall -Wno-missing-braces -Wextra -I ../include/ -L ../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm







# - `default:`: This line defines the target named "default." When you run `make` without specifying a target, it will attempt to build the first target in the file, which in this case is "default."

# - `g++`: This is the C++ compiler command that will be used to compile your code.

# - -std=c++23: This option tells the compiler to use the C++23 standard. Make sure your compiler version supports C++23, as this is a relatively recent standard. If you're using GCC, version 11 or later should support C++23.

# - `../src/*.cpp`: This argument tells the compiler to compile all `.cpp` files in the `../src/` directory.

# - `-o Game.exe`: This option tells the compiler to output the compiled program to a file named `Game.exe`.

# - `-O2`: This option sets the optimization level to 2, which instructs the compiler to perform optimizations that provide a good balance between code size and execution speed.

# - `-Wall`: This option enables most of the commonly used warning messages, helping you catch potential issues in your code.
# - `-Wno-missing-braces`: This option disables a specific warning related to missing braces, allowing your code to compile without issuing this particular warning.
# - -Wextra: This option enables extra warning flags that are not enabled by -Wall. It can help you catch additional potential issues in your code.

# - `-I ../include/`: This option tells the compiler where to find the header files that your code includes. In this case, it's looking in the `../include/` directory.

# - `-L ../lib/`: This option tells the linker where to find the library files that your code links against. In this case, it's looking in the `../lib/` directory.

# - `-lraylib`: This option tells the linker to link against the raylib library.
# - `-lopengl32`: This option tells the linker to link against the OpenGL library for Windows.
# - `-lgdi32`: This option tells the linker to link against the GDI (Graphics Device Interface) library for Windows.
# - `-lwinmm`: This option tells the linker to link against the Windows Multimedia library.