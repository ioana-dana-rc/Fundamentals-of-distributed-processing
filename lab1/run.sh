#!/bin/bash
# Compile the C++ code
mpic++ -std=c++20 -o blocking_communications blocking_communications.cpp
# Give execute permissions to the compiled executable
chmod +x blocking_communications
# Run the executable with 2 processes
mpirun -np 2 ./blocking_communications