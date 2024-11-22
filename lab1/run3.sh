#!/bin/bash
# Compile the C++ code
mpic++ -o non_blocking_communications non_blocking_communications.cpp
# Give execute permissions to the compiled executable
chmod +x non_blocking_communications
# Run the executable with 2 processes
mpirun -np 5 ./non_blocking_communications