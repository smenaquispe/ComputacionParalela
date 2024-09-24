#include <iostream>
#include <vector>
#include <chrono>  // Para medir el tiempo de ejecución

using namespace std;
using namespace std::chrono;

void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    // Inicializamos la matriz de resultado C
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
        }
    }
    
    // Multiplicación clásica de matrices (tres bucles anidados)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Tamaños de las matrices a evaluar
    vector<int> sizes = {100, 200, 300, 400, 500};

    for (int n : sizes) {
        // Inicializamos las matrices A, B y C
        vector<vector<int>> A(n, vector<int>(n, 1)); // Matriz A llena de 1s
        vector<vector<int>> B(n, vector<int>(n, 1)); // Matriz B llena de 1s
        vector<vector<int>> C(n, vector<int>(n, 0)); // Matriz C inicializada en 0

        // Medimos el tiempo de ejecución
        auto start = high_resolution_clock::now();
        multiplyMatrices(A, B, C, n);
        auto stop = high_resolution_clock::now();

        // Calculamos la duración en milisegundos
        auto duration = duration_cast<milliseconds>(stop - start);

        // Mostramos el tiempo de ejecución
        cout << "Tamaño de la matriz: " << n << "x" << n << " -> Tiempo: " << duration.count() << " ms" << endl;
    }

    return 0;
}
