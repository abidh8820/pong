# pong
Trash project using [smfl](https://www.sfml-dev.org/)

## Requirements

### SFML library

For Arch linux
``` bash
pacman -S sfml csfml
```

## Installation

``` bash
g++ -c main.cpp
g++ main.o -o pong -lsfml-graphics -lsfml-window -lsfml-system
./pong
```
Also you can build and run using 
``` bash
sh srun.sh
```

