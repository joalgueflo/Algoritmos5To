#include <iostream>
using namespace std;

// A01285612 - Jose A. Guerrero Flores

// Examen de Ubicación 6 de agosto del 2024

vector<vector<int>> crearMatriz(int filas, int columnas) {
    vector<vector<int>> matriz(filas, vector<int>(columnas));
    int valor = 1;

    // Creamos Matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = valor;
            valor++;
        }
    }

    return matriz;
}


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // Crear un vector donde guarde los valores de la matriz
    vector<int> result;

    // Iteradores
    int i, row = 0, col = 0;
    int m = matrix.size(); // Numero de filas
    int n = matrix[0].size(); // Numero de columnas

    // Continuamos loop mientras haya filas y columnas
    while (row < m && col < n) {
        // Iteramos sobre la primera fila y guardamos los valores en el vector "result"
        for (i = col; i < n; ++i) {
            result.push_back(matrix[row][i]);
        }
        // Nos movemos a la siguiente fila
        row++; 

        // Viajamos por la ultima columna y vamos de arriba a abajo guardando valores
        for (i = row; i < m; ++i) {
            result.push_back(matrix[i][n-1]);
        }
        // Nos movemos a la columna anterior
        n--;

        // Si hay filas restantes
        if (row < m) {
            // Iteramos sobre la ultima fila de derecha a izquierda
            for (i = n-1; i >= col; --i) {
                result.push_back(matrix[m-1][i]);
            }
            m--;
        }

        // Si hay columnas restantes
        if (col < n) {
            // Iteramos sobre la primera columna de izquierda a derecha
            for (i = m-1; i >= row; --i) {
                result.push_back(matrix[i][col]);
            }
            // Cambiamos de columna
            col++;
        }
    }
    // Regresamos valor y probamos yupiii
    return result;
}


int main()
{
    int m, n; // Definimos las variables m y n

    // Pedimos al usuario que ingrese el número de filas y columnas
    cout << "Ingresa el numero de filas (m): ";
    cin >> m;
    cout << "Ingresa el numero de columnas(n): ";
    cin >> n;

    // Creamos la matriz con los valores ingresados por el usuario
    vector<vector<int>> matrix = crearMatriz(m, n);

    // Llamamos a la función spiralOrder y guardamos el resultado en la variable result
    vector<int> result = spiralOrder(matrix);

    // Imprimimos el resultado valor por valor
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;

}
