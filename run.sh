#!/bin/bash
mkdir -p Build
cd ./Build
cmake ../
make
./Gradius
