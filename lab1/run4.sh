#!/bin/bash
# Compile the C++ code
mpic++ -std=c++20 -o matrix matrix.cpp
# Give execute permissions to the compiled executable
chmod +x matrix
# Run the executable with 4 processes
mpirun -np 0 ./matrix