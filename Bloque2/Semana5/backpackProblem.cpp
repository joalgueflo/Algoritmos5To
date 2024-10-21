#include <iostream>
#include <vector>
using namespace std;

// Función para resolver el problema de la mochila con backtracking
void knapsackBacktrack(int i, int currentWeight, int currentValue, int W, const vector<int> &values, const vector<int> &weights, int &maxValue) {
    // Caso base: si hemos recorrido todos los elementos
    if (i == values.size()) {
        if (currentWeight <= W) {
            maxValue = max(maxValue, currentValue); //Actualizamos valor maximo
        }
        return;
    }
    
    //No tomar el elemento actual
    knapsackBacktrack(i + 1, currentWeight, currentValue, W, values, weights, maxValue);
    
    // Tomar el elemento actual si no excede la capacidad
    if (currentWeight + weights[i] <= W) {
        knapsackBacktrack(i + 1, currentWeight + weights[i], currentValue + values[i], W, values, weights, maxValue);
    }
}

int main() {
    int N, W;
    
    //Pedimos data de entrada
    cout << "Introduce el número de elementos: ";
    cin >> N;
    
    vector<int> values(N), weights(N);
    
    cout << "Introduce los valores de los elementos: ";
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }
    
    cout << "Introduce los pesos de los elementos: ";
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    
    cout << "Introduce la capacidad máxima de la mochila: ";
    cin >> W;
    
    //Iniciamos valores
    int maxValue = 0;
    
    //Llamamos funcion y mostramos el resultado
    knapsackBacktrack(0, 0, 0, W, values, weights, maxValue);
    
    cout << "El valor máximo que se puede obtener es: " << maxValue << endl;
    
    return 0;
}