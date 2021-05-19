#!/bin/bash

clear

i686-w64-mingw32-g++ -c -Wall -std=c++17 src/*.cpp

#i686-w64-mingw32-g++ -o latest_binary.exe *.o -Iinclude/glfw3.h -Llib -lopengl32 -lglfw3dll -lgdi32 -luser32 -lkernel32 -static-libstdc++ 

i686-w64-mingw32-g++ -o latest_binary.exe *.o -lopengl32 -Iinclude/ -Llib/ -lglfw3dll -static-libstdc++ -static-libgcc -static

mv latest_binary.exe bin/windows

rm *.o
