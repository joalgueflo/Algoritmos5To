#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


// Funcion que verifica si es seguro asignar el color c al nodo v
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c, int V) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}


// Función recursiva para colorear
bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v, int V) {
    if (v == V) 
        return true; // Ya todo fue coloreado

    for (int c = 0; c < m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, V))
                return true;
            color[v] = -1;
        }
    }
    return false;
}

bool graphColoring(const vector<vector<int>>& graph, int m, int V) {
    //Iniciamos los colores como no asignados
    vector<int> color(V, -1);
    if (!graphColoringUtil(graph, m, color, 0, V)) {
        cout << "No es posible asignar colores a los nodos" << endl;
        return false;
    }

    // Imprimimos los colores asignados
    for (int i = 0; i < V; i++)
        cout << "Node: " << i << ", Assigned Color: " << color[i] << endl;
    return true;
}

int main() {

    //Tomamos los datos del usuario
    int V;
    cout << "Ingrese el tamaño del grafo: ";
    cin >> V;
    cin.ignore();

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Ingrese la matriz linea por linea y cada nodo separelo por un espacio. Tu matriz es de (" << V << "x" << V << "):" << endl;

    cout << "Ejemplo: 0 1 1 0 1" << endl;

    for (int i = 0; i < V; i++) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        for (int j = 0; j < V; j++) {
            iss >> graph[i][j];
        }
    }

    int m = V;
    graphColoring(graph, m, V);

    return 0;
}