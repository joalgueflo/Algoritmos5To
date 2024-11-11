#include <iostream>
#include <vector>
#include <algorithm>
#include <float.h>
#include <cmath>
using namespace std;

struct Punto {
    int x, y;
};

double distancia(Punto p1, Punto p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double paresMasCercanos(vector<Punto>& puntos) {
    double minDist = DBL_MAX;
    
    for(int i = 0; i < puntos.size(); i++) {
        for(int j = i + 1; j < puntos.size(); j++) {
            double dist = distancia(puntos[i], puntos[j]);
            minDist = min(minDist, dist);
        }
    }
    return minDist;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de puntos: ";
    cin >> n;

    vector<Punto> puntos;
    Punto p;

    cout << "Ingrese los puntos en formato x y (sin coma): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> p.x >> p.y;
        puntos.push_back(p);
    }

    double minDist = paresMasCercanos(puntos);
    cout << "La distancia mínima es: " << minDist << endl;

    return 0;
}