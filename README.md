# ManVsZombie
> The game is currently under development.  
A 2D top-down zombie shooter.

### Controls
- Use `Z` `Q` `S` `D` to move the player.
- Aim with the mouse and click the left button to shoot.

---

# Building and Development

## Informations
- Game developed using the [Raylib](https://www.raylib.com/) library.

## Prerequisites
- Ensure you have a compiler installed on your computer.
- There's no need to install Raylib separately. It is already precompiled and stored in the 'lib' folder.

## Compilation instructions ( if you are using the minGW compiler)

1. Open a PowerShell/cmd terminal and navigate to the project's directory.
   
2. Navigate to the build directory : 
```
cd build 
```

3. Generate the makefiles:
```
cmake -G "MinGW Makefiles" ..
```

4. Compile the project : (assuming that you use the minGW compiler)   
``` 
mingw32-make 
```

4. Run the game :   
```
.\debug.exe
```
