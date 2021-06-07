#!/bin/sh

clear

g++ -c -Wall -std=c++17 src/*.cpp -Iinclude
g++ -o latest_binary *.o -Wl,-rpath='$ORIGIN/../lib' -lGLU -lGL -Llib -lSDL2 -lSDL2_ttf

mv latest_binary bin
rm -r *.o
