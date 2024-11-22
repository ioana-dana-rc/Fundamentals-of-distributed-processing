#!/bin/bash
# Compile the C++ code
mpic++ -std=c++20 -o non_blocking_communications non_blocking_communications.cpp
# Give execute permissions to the compiled executable
chmod +x non_blocking_communications
# Run the executable with 2 processes
mpirun -np 5 ./non_blocking_communications