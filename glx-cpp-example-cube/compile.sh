#!/bin/bash

cd src

g++ -c -Wall -std=c++17 *.cpp
g++ -o process *.o -lGL -lX11

rm *.o
