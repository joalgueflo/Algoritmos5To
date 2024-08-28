// José A. Guerrero Flores
// A01285612
// Agosto 27, 2024
// Actividad 2.2 Implementación de "Sufix Array"

#include <iostream>
using namespace std;

vector<int> suffixArrayNaive(string S) {
    int n = S.length() + 1;
    vector<string> sa;
    vector<int> A(n);
    S = S + "$";
    for (int i = 0; i < n; i++){
        sa.push_back(S.substr(n - i - 1, i + 1));
    }
    sort(sa.begin(), sa.end());
    for (int i = 0; i < n; i++){
        A[i] = n - sa[i].size() + 1;
    }
    return A;
}






int main()
{
    string s;
    cout<<"Introduce un string: ";
    // Agarrar toda la linea
    getline(cin, s);
    cout<<"Tu string: "<<s<<endl; // Imprimir el string
    vector<int> sa = suffixArrayNaive(s);
    cout<<"Suffix Array: ";
    for (int i = 0; i < sa.size(); i++){
        cout<<sa[i]<<" ";
    }
    return 0;
}
