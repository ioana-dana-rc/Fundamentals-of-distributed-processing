//
// Created by Ioana Recianu on 23.11.2024.
//
#include <iostream>
#include <mpi.h>

void generate_matrix(const int n, std::vector<std::vector<int>>& a) {
    for( int i = 0; i < n; i++) {
        for(int j = 0; j <n; j++) {
            a[i][j] = i * j +1;
            std::count<<a[i][j]<<" ";
        }
    }
}

void generate_vector(const int n, std::vector<int>& v) {
    for(int i=0; i<n; i++) {
        v[i] = i + 4;
    }
}

void compute_product(const int n, const std::vector<int>& v, const std::vector<std::vector<int>>& a, std::vector<int>& product) {
    for(int i=0; i<n; i++) {
        for(int j=0;j<n;j++) {
            product[i] += a[i][j] * v[j];
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << product[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    int count, myrank;
    int N = 5;
    std::vector matrix(N, std::vector<int>(N));
    std::vector<int> vector(N), product(N, 0);

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &count);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);


    if (myrank == 0) {
        generate_matrix(N, matrix);
        generate_vector(N, vector);

        const auto start = std::chrono::high_resolution_clock::now();
        compute_product(N, vector, matrix, product);
        const auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;
    }
    MPI_Finalize();
    return 0;
}