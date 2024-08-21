// José A. Guerrero Flores
// A01285612
// 20 de agosto del 2024
// Actividad 1.2.1 Implementación de la técnica de programación "Programación dinámica"

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;



void dpSolution(int precioTotal, int pagado, vector<int> monedas) {
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

    int n = monedas.size();
    // Crear una tabla dp donde dp[i] representa el mínimo número de monedas necesarias para obtener el cambio i
    vector<int> dp(resto + 1, INT_MAX);
    dp[0] = 0; // No se necesita ninguna moneda para obtener un cambio de 0

    // Llenar la tabla dp usando una relación de recurrencia
    for (int i = 1; i <= resto; ++i) {
        for (int j = 0; j < n; ++j) {
            if (monedas[j] <= i && dp[i - monedas[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - monedas[j]] + 1);
            }
        }
    }

    // Si dp[resto] es INT_MAX, no es posible dar el cambio con las monedas disponibles
    if (dp[resto] == INT_MAX) {
        cout << "No es posible dar el cambio con las monedas disponibles" << endl;
    } else {
        cout << "El cambio a dar es: " << endl;
        int temp = resto;
        vector<int> resultado(n, 0);
        // Reconstruir la solución para mostrar cuántas monedas de cada denominación se necesitan
        while (temp > 0) {
            for (int j = 0; j < n; ++j) {
                if (monedas[j] <= temp && dp[temp - monedas[j]] == dp[temp] - 1) {
                    resultado[j]++;
                    temp -= monedas[j];
                    break;
                }
            }
        }
        // Imprimir el resultado
        for (int i = 0; i < n; ++i) {
            if (resultado[i] > 0) {
                cout << resultado[i] << " moneda(s) de " << monedas[i] << endl;
            }
        }
    }
}

// Primer solución sin programación dinámica :(

// void Solution(int precioTotal, int pagado, vector<int> monedas){
//     int resto = pagado - precioTotal;

//     if (resto == 0){
//         cout << "No hay cambio para dar" << endl;
//     }
//     else if (resto < 0){
//         cout << "Falta dinero para pagar el producto" << endl;
//     }
//     else{
//         cout << "El cambio a dar es: " << endl;
//         // Ordenar monedas de mayor a menor
//         sort(monedas.begin(), monedas.end(), greater<int>());
//         // Checar si la primera moneda no es mas grande que el precio restante a pagar
//         if (monedas[0] > resto){
//             cout << "No hay monedas suficientes para dar cambio" << endl;
//         }
//         else{
//             // Iterar sobre las monedas
//             for (int i = 0; i < monedas.size(); i++){
//                 // Si la moneda es menor o igual al precio restante
//                 if (monedas[i] <= resto){
//                     // Calcular cuantas monedas de ese valor se pueden dar
//                     int numMonedas = resto / monedas[i];
//                     // Actualizar el precio restante
//                     resto -= numMonedas * monedas[i];
//                     // Imprimir el valor de la moneda y cuantas monedas se dieron
//                     cout << monedas[i] << " : " << numMonedas << endl;
//                 }
//             }
//         }
//     }
// }







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
    dpSolution(precioTotal, pagado, monedas);

    return 0;
}
