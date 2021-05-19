#!/bin/bash

clear

g++ -c -Wall -std=c++17 src/*.cpp
g++ -o latest_binary *.o -lGL -lglfw

mv latest_binary build

rm *.o
