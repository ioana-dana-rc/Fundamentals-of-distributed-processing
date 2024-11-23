#!/bin/bash
# Compile the C++ code
mpic++ -std=c++20 -o producer_consumer producer_consumer.cpp
# Give execute permissions to the compiled executable
chmod +x producer_consumer
# Run the executable with 2 processes
mpirun -np 5 ./producer_consumer