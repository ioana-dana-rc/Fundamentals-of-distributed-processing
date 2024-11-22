//
// Created by Ioana Recianu on 22.11.2024.
//
#include <iostream>
#include <mpi.h>

int main(int argc, char **argv) {
    int count, myrank;

    MPI_Init (&argc, &argv);
    MPI_Comm_size (MPI_COMM_WORLD, &count);
    MPI_Comm_rank (MPI_COMM_WORLD, &myrank);

    const int array_size = 2000;
    double data[array_size];
    MPI_Request request;

    if (myrank == 0) {
        // Process 0 initializes and sends data
        for (int i = 0; i < array_size; ++i) {
            data[i] = static_cast<double>(i);
        }
        MPI_Isend(data, array_size, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &request);
        std::cout << "Process 0 sent data array" << std::endl;
    } else if (myrank == 1) {
        // Process 1 receives data
        MPI_Irecv(data, array_size, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &request);
        std::cout << "Process 1 received data array" << std::endl;
    }
    // Ensure non-blocking operations complete
    MPI_Wait(&request, MPI_STATUS_IGNORE);

    MPI_Finalize();
    return 0;
}