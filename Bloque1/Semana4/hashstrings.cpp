// José A. Guerrero Flores
// A01285612
// Agosto 27, 2024
// Actividad 2.1 Implementación de "Hash String"

#include <iostream>
using namespace std;

long long prhf(string S) {
    int n = S.length();
    int p = 31;
    int m = 1000000000 + 9;
    long long valorHash = 0;
    long long potencia = 1;
    for (int i = 0; i < n; i++) {
        valorHash = (valorHash + (S[i] - 'a' + 1) * potencia) % m;
        potencia = (potencia * p) % m;
}
return valorHash;
}


int main()
{
    string s;
    cout<<"Introduce un string: ";
    // Agarrar toda la linea
    getline(cin, s);
    cout<<"Tu string: "<<s<<endl; // Imprimir el string
    cout<<"Valor en hash: "<<prhf(s)<< endl; // Imprimir el valor en hash
    return 0;
}
