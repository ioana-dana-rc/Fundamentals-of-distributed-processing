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

    MPI_Finalize();
    return 0;
}
