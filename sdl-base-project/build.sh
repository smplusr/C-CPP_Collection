#!/bin/sh

clear

g++ -c -Wall -std=c++17 src/*.cpp -Iinclude
g++ -o latest_binary *.o -Wl,-rpath="$ORIGIN/../lib" -Llib -lSDL2

mv latest_binary bin
rm -r *.o
