// A01285612 José A. Guerrero Flores
// Septiembre 1 del 2024
// Actividad 1.3 Implementación de la técnica de programación "backtracking" y "ramificación y poda"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Función para verificar si una casilla es segura
bool esSeguro(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    int M = maze.size();
    int N = maze[0].size();
    // Verificar si la casilla está dentro de los límites del laberinto y si es un camino válido
    return (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

// Solución Backtracking
bool resolverLaberintoBacktrackingUtil(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    int M = maze.size();
    int N = maze[0].size();
    
    // Si llegamos a la meta (M-1, N-1)
    if (x == M - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }
    
    // Si la casilla actual es segura
    if (esSeguro(maze, x, y, sol)) {
        sol[x][y] = 1;
        
        // Moverse hacia abajo
        if (resolverLaberintoBacktrackingUtil(maze, x + 1, y, sol))
            return true;
        
        // Moverse hacia la derecha
        if (resolverLaberintoBacktrackingUtil(maze, x, y + 1, sol))
            return true;
        
        // Backtracking, desmarcar este camino
        sol[x][y] = 0;
        return false;
    }
    
    return false;
}

vector<vector<int>> resolverLaberintoBacktracking(vector<vector<int>>& maze) {
    int M = maze.size();
    int N = maze[0].size();
    vector<vector<int>> sol(M, vector<int>(N, 0));
    
    if (resolverLaberintoBacktrackingUtil(maze, 0, 0, sol))
        return sol;
    
    return vector<vector<int>>();  // Si no se encuentra solución
}


// Solución Ramificación y Poda
bool resolverLaberintoRamificacionPodaUtil(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    int M = maze.size();
    int N = maze[0].size();
    
    // Si llegamos a la meta (M-1, N-1)
    if (x == M - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }
    
    if (esSeguro(maze, x, y, sol)) {
        sol[x][y] = 1;
        
        // Intentar moverse hacia abajo
        if (resolverLaberintoRamificacionPodaUtil(maze, x + 1, y, sol))
            return true;
        
        // Intentar moverse hacia la derecha
        if (resolverLaberintoRamificacionPodaUtil(maze, x, y + 1, sol))
            return true;
        
        // Si ninguna dirección funciona, desmarcar esta casilla (poda)
        sol[x][y] = 0;
        return false;
    }
    
    return false;
}

vector<vector<int>> resolverLaberintoRamificacionPoda(vector<vector<int>>& maze) {
    int M = maze.size();
    int N = maze[0].size();
    vector<vector<int>> sol(M, vector<int>(N, 0));
    
    if (resolverLaberintoRamificacionPodaUtil(maze, 0, 0, sol))
        return sol;
    
    return vector<vector<int>>();  // Si no se encuentra solución
}


int main() {
    int M, N;
    cin >> M >> N;

    // Creamos el laberinto
    vector<vector<int>> maze(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> maze[i][j];
        }
    }
    
    // Solución utilizando Backtracking
    vector<vector<int>> solBacktracking = resolverLaberintoBacktracking(maze);
    if (!solBacktracking.empty()) {
        cout << "Solución utilizando 'Backtracking:'" << endl;
        for (auto& row : solBacktracking) {
            for (auto& cell : row)
                cout << cell << " ";
            cout << endl;
        }
    } else {
        cout << "No se encontró solución utilizando 'Backtracking.'" << endl;
    }

	// Solución utilizando Ramificación y Poda
    vector<vector<int>> solRamificacionPoda = resolverLaberintoRamificacionPoda(maze);
    if (!solRamificacionPoda.empty()) {
        cout << "Solución utilizando 'Ramificación y Poda:'" << endl;
        for (auto& row : solRamificacionPoda) {
            for (auto& cell : row)
                cout << cell << " ";
            cout << endl;
        }
    } else {
        cout << "No se encontró solución utilizando 'Ramificación y Poda.'" << endl;
    }

    return 0;
}


// Entrada 1
// 3
// 3

// 1 0 0
// 1 1 0
// 1 1 1

// Salida
// 1 0 0
// 1 0 0
// 1 1 1

// Entrada 2
// 3
// 3

// 1 0 0
// 0 1 0
// 0 0 1

// Salida
// No se encontró solución utilizando Backtracking.
// No se encontró solución utilizando Ramificación y Poda.

// Entrada 3
// 4
// 4

// 1 0 0 0
// 1 1 0 1
// 0 1 0 0
// 1 1 1 1

// Salida
// 1 0 0 0
// 1 1 0 0
// 0 1 0 0
// 0 1 1 1

// Entrada 4
// 2
// 2

// 1 1
// 0 1

// Salida
// 1 1
// 0 1