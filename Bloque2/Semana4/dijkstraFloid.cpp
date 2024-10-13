#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iomanip>
#include <iostream>
using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    int n;
    vector<vector<int>> adj;

public:
    //Constructor
    Graph(int nodes) : n(nodes), adj(nodes, vector<int>(nodes, -1)) {}

    //Agregamos artistas
    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
    }

    //Algoritmo Dijkstra
    vector<int> dijkstra(int start) {
        vector<int> dist(n, INF);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (int v = 0; v < n; ++v) {
                if (adj[u][v] != -1) {
                    if (dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return dist;
    }

    //Floyd
    vector<vector<int>> floyd() {
        vector<vector<int>> dist = adj;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] == -1) {
                    dist[i][j] = INF;
                }
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        return dist;
    }
};

int main() {
    //Pedimos el tamaño de la columna nxn
    int n;
    cin >> n;
    //Creamos el grafo
    Graph g(n);

    //Leemos la matriz de adyacencias y agregamos los artistas al grafo
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w;
            cin >> w;
            if (w != -1) {
                g.addEdge(i, j, w);
            }
        }
    }

    // Ejecutamos el algoritmo de Dijkstra desde cada nodo y mostramos las distancias
    cout << "Dijkstra : "<<endl;
    for (int i = 0; i < n; ++i) {
        vector<int> distances = g.dijkstra(i);
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                cout << "node " << i + 1 << " to node " << j + 1 << " : " << distances[j] << " "<<endl;
            }
        }
    }
    cout << endl;

    //Ejecutamos el algoritmo de Floyd y mostramos la nueva matriz de distancias.
    cout << "Floyd : ";
    vector<vector<int>> floydDist = g.floyd();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (floydDist[i][j] == INF) {
                cout << "-1 ";
            } else {
                cout << floydDist[i][j] << " ";
            }
        }
    }
    cout << endl;

    return 0;
}