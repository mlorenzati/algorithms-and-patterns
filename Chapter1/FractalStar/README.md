# Fractal Star
Draw with recursion a fractal star

# Description
This example uses QT6 and recursive algorithms to draw a recursive pattern

# Setup
Install Qt
## Mac
```
brew install qt
```
## Linux
```
sudo apt update
sudo apt install build-essential
sudo apt install qtcreator
sudo apt install qt6-default
```
## Windows (MSYS2 environment)  
Install [MSYS2](https://www.msys2.org/)
```
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-qt6-base
```

# Build
```bash
cmake -Bbuild
cmake --build build/ -j 4
```
