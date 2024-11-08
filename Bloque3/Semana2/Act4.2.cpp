#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Estructura para representar un punto
struct Punto {
    int x, y;
};

//Punto de referencia
Punto p0;

// Caclula la distancia entre dos puntos
int distSq(Punto p1, Punto p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

//funcion para determinar la orientacion de 3 puntos
int orientation(Punto p1, Punto p2, Punto p3) {

    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

//Funcion para comparar 2 puntos
bool compare(Punto p1, Punto p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p2) >= distSq(p0, p1);
    return (o == 2);
}



// Funcion para obtener el siguiente punto en el stack
Punto nextToTop(stack<Punto>& S) {
    Punto p1 = S.top();
    S.pop();
    Punto res = S.top();
    S.push(p1);
    return res;
}


// Funcion Graham Scan
vector<Punto> grahamScan(vector<Punto>& points) {
    // Encuentra el punto más bajo
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y < ymin || (points[i].y == ymin && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }


    // Coloca el punto más bajo en la primera posición
    swap(points[0], points[min]);
    p0 = points[0];


    // Sortea los puntos restantes
    sort(points.begin() + 1, points.end(), compare);




    // Crear stack para almacenar los puntos
    stack<Punto> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < points.size(); i++) {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }




    // Convertir stack a vector
    vector<Punto> hull;
    while (!S.empty()) {
        hull.push_back(S.top());
        S.pop();
    }
    reverse(hull.begin(), hull.end());
    return hull;
}


int main() {
    vector<Punto> points;
    Punto p1;

    int n;

    cout << "Ingrese la n cantidad de puntos a escribir: " << endl;
    cin >> n;

    //Obtener puntos
    for (int i = 0; i < n; i++) {
        cin >> p1.x >> p1.y;
        points.push_back(p1);
    }

    // Llama a la función grahamScan
    vector<Punto> hull = grahamScan(points);


    cout << endl;
    cout << "Resultado" << endl;
    
    // Imprime los puntos del convex hull
    for (Punto p1 : hull) {
        cout << p1.x << " " << p1.y << endl;
    }

    return 0;
}

// 0 2
// 1 2 
// 2 3
// 4 5
// 1 0
// 2 2
// 3 2
// 3 4