#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


struct Punto {
    double x, y;
    Punto(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

// Estructura para representar un segmento de línea
struct Segmento {
    Punto p1, p2;
    Segmento(Punto _p1, Punto _p2) : p1(_p1), p2(_p2) {}
};

// Función para calcular el producto cruz de dos vectores
double productoCruz(const Punto& O, const Punto& A, const Punto& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Función para verificar si un punto está en un segmento
bool onSegment(const Punto& p, const Punto& q, const Punto& r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

//Función para determinar si dos segmentos se intersectan
bool doIntersect(const Segmento& seg1, const Segmento& seg2) {
    Punto p1 = seg1.p1, q1 = seg1.p2;
    Punto p2 = seg2.p1, q2 = seg2.p2;

    //Calculamos las orientaciones necesaras
    double d1 = productoCruz(p1, q1, p2);
    double d2 = productoCruz(p1, q1, q2);
    double d3 = productoCruz(p2, q2, p1);
    double d4 = productoCruz(p2, q2, q1);

    //Revisamos intersercción
    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;

    //Casos especiales donde los segmentos son colineales
    if (d1 == 0 && onSegment(p1, p2, q1)) return true;
    if (d2 == 0 && onSegment(p1, q2, q1)) return true;
    if (d3 == 0 && onSegment(p2, p1, q2)) return true;
    if (d4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<bool> results;
    
    for(int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        
        string coord1, coord2, coord3, coord4;
        ss >> coord1 >> coord2 >> coord3 >> coord4;
        
        // Procesar cada par de coordenadas
        double x1, y1, x2, y2, x3, y3, x4, y4;
        
        // Extraer coordenadas de manera correcta en formato "x1,y1 x2,y2 x3,y3 x4,y4"
        sscanf(coord1.c_str(), "%lf,%lf", &x1, &y1);
        sscanf(coord2.c_str(), "%lf,%lf", &x2, &y2);
        sscanf(coord3.c_str(), "%lf,%lf", &x3, &y3);
        sscanf(coord4.c_str(), "%lf,%lf", &x4, &y4);
        
        //Creamos segmentos y verifica intersección
        Segmento seg1(Punto(x1, y1), Punto(x2, y2));
        Segmento seg2(Punto(x3, y3), Punto(x4, y4));
        
        results.push_back(doIntersect(seg1, seg2));
    }
    
    //Imprimir resultados
    for (bool result : results) {
        cout << (result ? "True" : "False") << endl;
    }
    
    return 0;
}