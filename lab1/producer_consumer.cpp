//
// Created by Ioana Recianu on 23.11.2024.
//
#include <iostream>
#include <mpi.h>

void producer(int rank) {
    MPI_Request request;

    // Initialize data
    double value = rank * 2000;

    // Send data to consumer (process 0)
    MPI_Isend(&value, 1, MPI_DOUBLE, 0, rank, MPI_COMM_WORLD, &request);
    MPI_Wait(&request, MPI_STATUS_IGNORE);
    std::cout << "Producer " << rank << " sent data array" << std::endl;
}

void consumer(int num_producers) {
    MPI_Request request;
    double value;

    for (int i = 1; i <= num_producers; ++i) {
        // Receive data from producer
        MPI_Irecv(&value, 1, MPI_DOUBLE, i, i, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, MPI_STATUS_IGNORE);

        // Process received data (for demonstration, we just print the first element)
        std::cout << "Consumer received data from producer " << i << ": " << value << std::endl;
    }
}

int main(int argc, char **argv) {
    int count, myrank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &count);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0) {
        // Process 0 is the consumer
        consumer(count - 1);
    } else {
        // Other processes are producers
        producer(myrank);
    }

    MPI_Finalize();
    return 0;
}