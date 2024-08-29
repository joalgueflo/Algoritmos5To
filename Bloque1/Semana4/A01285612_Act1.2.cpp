
// José A. Guerrero Flores
// A01285612
// 28 de agosto del 2024
// Actividad 1.2.2 Implementación de la técnica de programación "Algoritmos Greedy"

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;



void greedySolution(int precioTotal, int pagado, vector<int> monedas) {
    // Sacamos el resto
    int resto = pagado - precioTotal;

    // Si el resto es negativo, no se puede dar cambio
    if (resto < 0) {
        cout << "Falta dinero para pagar ese producto" << endl;
        return;
    } 
    // Si el resto es 0, no hay cambio que dar
    else if (resto == 0) {
        cout << "No hay cambio por dar" << endl;
        return;
    }

    // Ordenar las monedas en orden descendente
    sort(monedas.rbegin(), monedas.rend());

    // Vector para guardar cuántas monedas de cada denominación se necesitan
    cout << "El cambio a dar es: " << endl;
    vector<int> resultado(monedas.size(), 0); 

    // Usar el algoritmo voraz para dar el cambio
    for (int i = 0; i < monedas.size(); ++i) {
        while (resto >= monedas[i]) {
            resto -= monedas[i];
            resultado[i]++;
        }
    }

    // Si no se pudo dar el cambio exacto
    if (resto != 0) {
        cout << "No es posible dar el cambio exacto con las monedas disponibles" << endl;
    } else {
        // Imprimir el resultado
        for (int i = 0; i < monedas.size(); ++i) {
            if (resultado[i] > 0) {
                cout << resultado[i] << " moneda(s) de " << monedas[i] << endl;
            }
        }
    }
}

// Casos de Prueba

// Caso de prueba 1:

// Ingrese el número de denominaciones de monedas: 4
// Ingrese las denominaciones de las monedas, una por línea:
// 1
// 2
// 5
// 10
// Ingrese el precio del producto: 500
// Ingrese la cantidad pagada: 500

// No hay cambio por dar


// Caso de prueba 2:

// Ingrese el número de denominaciones de monedas: 4
// Ingrese las denominaciones de las monedas, una por línea:
// 1
// 2
// 5
// 10
// Ingrese el precio del producto: 678
// Ingrese la cantidad pagada: 600

// Falta dinero para pagar ese producto


// Caso de prueba 3:

// Ingrese el número de denominaciones de monedas: 4
// Ingrese las denominaciones de las monedas, una por línea:
// 1
// 2
// 5
// 10
// Ingrese el precio del producto: 450
// Ingrese la cantidad pagada: 500
// 5 moneda(s) de 10
// 0 moneda(s) de 5
// 0 moneda(s) de 2
// 0 moneda(s) de 1


// Caso de prueba 4:

// Ingrese el número de denominaciones de monedas: 5
// Ingrese las denominaciones de las monedas, una por línea:
// 1
// 2
// 5
// 10
// 20
// Ingrese el precio del producto: 600
// Ingrese la cantidad pagada: 700
// 5 moneda(s) de 20
// 0 moneda(s) de 10
// 0 moneda(s) de 5
// 0 moneda(s) de 2
// 0 moneda(s) de 1


// Caso de prueba 5:

// Ingrese el número de denominaciones de monedas: 5
// Ingrese las denominaciones de las monedas, una por línea:
// 1
// 2
// 5
// 10
// 20
// Ingrese el precio del producto: 863
// Ingrese la cantidad pagada: 900
// 1 moneda(s) de 20
// 1 moneda(s) de 10
// 1 moneda(s) de 5
// 1 moneda(s) de 2
// 0 moneda(s) de 1


// Caso de prueba 6:

// Ingrese el número de denominaciones de monedas: 5
// Ingrese las denominaciones de las monedas, una por línea:
// 1
// 2
// 5
// 10
// 20
// Ingrese el precio del producto: 1017
// Ingrese la cantidad pagada: 1200
// 9 moneda(s) de 20
// 0 moneda(s) de 10
// 0 moneda(s) de 5
// 1 moneda(s) de 2
// 1 moneda(s) de 1


int main()
{
    // Pedimos el numero de monedas
    int numMonedas;
    cout << "Ingrese el número de denominaciones de monedas: " << endl;
    cin >> numMonedas;
    
    // Pedimos los valores de las monedas
    vector<int> monedas(numMonedas);
    cout << "Ingrese las monedas: ";
    for(int i = 0; i < numMonedas; i++){
        cin >> monedas[i];
    }

    // Precio del producto y cantidad pagada
    int precioTotal;
    cout << "Ingrese el precio del producto: ";
    cin >> precioTotal;
    int pagado;
    cout << "Ingrese la cantidad pagada: ";
    cin >> pagado;

    // Llamamos a la función que resuelve el problema
    greedySolution(precioTotal, pagado, monedas);

    return 0;
}
