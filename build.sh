#!/bin/bash
if [ -d "build" ]
then 
	rm -r build
fi
if [ -d "bin" ]
then 
	rm -r build
fi
mkdir build
mkdir bin
cd build
cmake ..
make
make install
cd ..
