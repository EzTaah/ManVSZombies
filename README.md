# ManVsZombie

A 2D top-down game where a player character can move, wield a weapon, and eliminate zombies.   
The game is currently under development.

> Game developed using the [Raylib](https://www.raylib.com/) library.


## Features
- 2D top-down view 
- Collision detection
- Zombie adversaries

### Keys
- Use `Z` `Q` `S` `D` to move the player.
- Aim with the mouse and click the left button to shoot.

---

## Building and Development

### Informations
- /

### Compilation instructions ( if you are using the minGW compiler)

1. Navigate to the build directory : 
```
cd build 
```

2. Generate the makefiles:
```
cmake -G "MinGW Makefiles" ..
```

3. Compile the project :   
``` 
mingw32-make 
```

4. Run the game :   
```
.\debug.exe
```