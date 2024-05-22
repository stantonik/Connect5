
# Connect5

> A C++ remake of the famous game.

**Install**

***Requierements:***

- C++ > v.11
- ncurses

*Window*:

```bash
g++ src\*.cpp src\gui\*.cpp -o bin\Connect5 -std=c++11 -Iinclude -lncurses -IC:\MinGW\include\ncurses -LC:\MinGW\lib
```

*MacOS/Linux*:

```bash
g++ src/*.cpp src/gui/*.cpp -o bin/Connect5 -std=c++11 -Iinclude -lncurses
```
Or simply use the makefile.
