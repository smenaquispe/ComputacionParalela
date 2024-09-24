#include <iostream>
#include <vector>
#include <chrono>  // Para medir el tiempo de ejecución

using namespace std;
using namespace std::chrono;

// Variables globales para contar accesos a memoria
long long total_memory_accesses = 0;

// Función para registrar accesos a memoria
void log_memory_access(const int& value) {
    total_memory_accesses++;
}

// Función de multiplicación de matrices con bloques
void blockMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n, int blockSize) {
    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            for (int k = 0; k < n; k += blockSize) {
                for (int ii = i; ii < min(i + blockSize, n); ++ii) {
                    for (int jj = j; jj < min(j + blockSize, n); ++jj) {
                        int sum = 0;
                        for (int kk = k; kk < min(k + blockSize, n); ++kk) {
                            log_memory_access(A[ii][kk]); // Acceso a A
                            log_memory_access(B[kk][jj]); // Acceso a B
                            sum += A[ii][kk] * B[kk][jj];
                        }
                        C[ii][jj] += sum;
                        log_memory_access(C[ii][jj]); // Acceso a C
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
        cout << "Total de accesos a memoria: " << total_memory_accesses << endl;

        // Reiniciamos el contador de accesos a memoria para la próxima iteración
        total_memory_accesses = 0;
    }

    return 0;
}
