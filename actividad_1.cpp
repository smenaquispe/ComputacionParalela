#include <iostream>
#include <ctime>  // Para medir el tiempo de ejecución

// Definir el valor de MAX
#define MAX 10000

int main() {
    // Asignación dinámica de memoria para la matriz A y los vectores x e y
    double** A = new double*[MAX];
    for (int i = 0; i < MAX; i++) {
        A[i] = new double[MAX];
    }
    
    double* x = new double[MAX];
    double* y = new double[MAX];

    // Inicializar A y x, y asignar y = 0
    for (int i = 0; i < MAX; i++) {
        x[i] = 1.0;  // Por ejemplo, inicializamos el vector x a 1.0
        y[i] = 0.0;  // Inicializar el vector y a 0.0
        for (int j = 0; j < MAX; j++) {
            A[i][j] = 1.0;  // Inicializamos la matriz A a 1.0
        }
    }

    // Medir el tiempo de la primera sección de bucles
    clock_t start1 = clock();
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    
    clock_t end1 = clock();
    double time1 = double(end1 - start1) / CLOCKS_PER_SEC;
    
    std::cout << "Tiempo para la primera sección de bucles: " << time1 << " segundos" << std::endl;

    // Asignar y = 0 nuevamente antes de la segunda sección de bucles
    for (int i = 0; i < MAX; i++) {
        y[i] = 0.0;
    }

    // Medir el tiempo de la segunda sección de bucles
    clock_t start2 = clock();
    
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
    
    clock_t end2 = clock();
    double time2 = double(end2 - start2) / CLOCKS_PER_SEC;
    
    std::cout << "Tiempo para la segunda sección de bucles: " << time2 << " segundos" << std::endl;

    // Liberar la memoria dinámica
    for (int i = 0; i < MAX; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] x;
    delete[] y;

    return 0;
}
