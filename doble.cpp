#include<iostream>
#include<chrono>  // Para medir el tiempo
using namespace std;

int main() {
    
    cout<<"a"<<endl;
    const unsigned int MAX = 1000;
    int i, j;


    // double A[MAX][MAX] = {{1.0, 2.0}, {3.0, 4.0}}; // Ejemplo de valores en A
    // double x[MAX] = {1.0, 1.0};  // Ejemplo de valores en x
    // double y[MAX] = {0.0, 0.0};  // Inicializar y a 0
    double A[MAX][MAX], x[MAX], y[MAX];  // Declarar las matrices y vectores

    /* First pair of loops */
    auto start1 = chrono::high_resolution_clock::now();  // Inicio del tiempo del primer par de bucles
    for (i = 0; i < MAX; i++) {
        y[i] = 0.0;  // Inicializar y[i] a 0 antes de la suma
        for (j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
            cout << "i: " << i << " j: " << j << " y[i]: " << y[i] << endl;
        }
    }

    auto end1 = chrono::high_resolution_clock::now();  // Fin del tiempo del primer par de bucles
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();  // Duración en microsegundos

    cout << "Tiempo de ejecución del primer par de bucles: " << duration1 << " microsegundos" << endl;
    cout << "-------------------" << endl;
    
    // Reinicializar el vector y para el segundo cálculo
    for (i = 0; i < MAX; i++) {
        y[i] = 0.0;  // Inicializar y[i] a 0 nuevamente
    }

    /* Second pair of loops */
    auto start2 = chrono::high_resolution_clock::now();  // Inicio del tiempo del segundo par de bucles
    
    for (j = 0; j < MAX; j++) {
        for (i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
            cout << "i: " << i << " j: " << j << " y[i]: " << y[i] << endl;
        }
    }

    auto end2 = chrono::high_resolution_clock::now();  // Fin del tiempo del segundo par de bucles
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();  // Duración en microsegundos

    cout << "Tiempo de ejecución del segundo par de bucles: " << duration2 << " microsegundos" << endl;

    return 0;
}
