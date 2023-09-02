<div align="center">

2D-zombie-shooter
=========

"A 2D top-down multiplayer game where a player can move and eliminate zombies."  

<br undefined>

**The game is currently under development.**

<br undefined>
<br undefined>
<br undefined>
</div>

---

# Building and Development

**This game is build on Windows with [CMake](https://cmake.org/download/) and the [MinGW](https://winlibs.com/) compiler.**

<br undefined>

**Here are the compilation instructions :**


1. Open a PowerShell terminal and navigate to the project's directory.

2. Create a build directory : 
```
mkdir build
```

3. Navigate to the build directory : 
```
cd build 
```

4. Generate the makefiles (Choose between the debug and the release version) :
```
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
```
```
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
```

5. Compile the project :
``` 
mingw32-make 
```

5. Run the game (Choose between the debug and the release version) :   
```
.\debug.exe
```
```
.\release.exe
```
 
