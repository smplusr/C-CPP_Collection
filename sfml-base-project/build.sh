#!/bin/sh

clear

g++ -c -Wall -std=c++17 src/*.cpp -Iinclude -DSFML_STATIC
g++ -o latest_binary *.o -Wl,-rpath,lib -Llib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

mv latest_binary bin
rm -r *.o
