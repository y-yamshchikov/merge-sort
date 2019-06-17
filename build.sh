#!/bin/bash
mv merge old_merge
g++ -c merge.cpp -std=c++17
g++ -o merge merge.o
