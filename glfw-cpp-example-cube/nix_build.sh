#!/bin/bash

clear

g++ -c -Wall -std=c++17 src/*.cpp -Iinclude  
g++ -o latest_binary *.o -Wl,-rpath='$ORIGIN/../../lib' -Llib -lGL -lglfw

mv latest_binary bin/nix

rm *.o
