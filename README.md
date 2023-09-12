<div align="center">

# 2Dshooter

*Developed in August 2023*

<br>

Use `Z` `Q` `S` `D` to move the player, aim with the mouse and click the left button to shoot.

<br>

This game is developed in C++ using Object-Oriented Programming principles and leverages the [raylib](https://www.raylib.com/) library for graphical rendering.


<br>
<br>

</div>

---

# Building and Development

The game was developed on a Windows platform, utilizing CMake for build configuration and the MinGW compiler for code compilation.  
Follow the instructions below if you wish to compile using this setup.

<br>

## Compilation instructions

1. Open a PowerShell terminal and navigate to the project's directory.

<br>

2. Create a build directory : 
```bash
mkdir build
```

<br>

3. Navigate to the build directory : 
```bash
cd build 
```

<br>

4. Generate the makefiles (Choose between the debug and the release version) :
```bash
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
```
```bash
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
```

<br>

5. Compile the project :
```bash
mingw32-make 
```

<br>

6. Navigate to the datasrc directory : 
```bash
cd ./../datasrc
```

<br>

7. Run the game (Choose between the debug and the release version) :   
```bash
./../build/debug.exe
```
```bash
./../build/release.exe
```
