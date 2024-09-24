#include <iostream>
#include <vector>
#include <chrono>  // Para medir el tiempo de ejecución

using namespace std;
using namespace std::chrono;

void blockMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n, int blockSize) {
    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            for (int k = 0; k < n; k += blockSize) {
                for (int ii = i; ii < min(i + blockSize, n); ++ii) {
                    for (int jj = j; jj < min(j + blockSize, n); ++jj) {
                        int sum = 0;
                        for (int kk = k; kk < min(k + blockSize, n); ++kk) {
                            sum += A[ii][kk] * B[kk][jj];
                        }
                        C[ii][jj] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    // Tamaños de las matrices a evaluar
    vector<int> sizes = {100, 200, 300, 400, 500};
    int blockSize = 50;  // Tamaño del bloque

    for (int n : sizes) {
        // Inicializamos las matrices A, B y C
        vector<vector<int>> A(n, vector<int>(n, 1));
        vector<vector<int>> B(n, vector<int>(n, 1));
        vector<vector<int>> C(n, vector<int>(n, 0));

        // Medimos el tiempo de ejecución
        auto start = high_resolution_clock::now();
        blockMultiply(A, B, C, n, blockSize);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Tamaño de la matriz: " << n << "x" << n << " -> Tiempo: " << duration.count() << " ms" << endl;
    }

    return 0;
}
