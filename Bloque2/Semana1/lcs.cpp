// Actividad en clase LCS (Longest Common Substring)
// José A. Guerrero Flores
// A01285612
// 17 de septiembre del 2024

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Función que devuelve el substring común más largo entre dos strings
string longestCommonSubstring(const string& str1, const string& str2) {
    // Sacamos las longitudes de los strings
    int m = str1.size();
    int n = str2.size();
    int maxLength = 0; 
    int endIndex = 0; 

    // Creamos un vector de vectores de enteros de tamaño m+1 x n+1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Llenamos la matriz dp con la longitud del substring común más largo
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Si los caracteres son iguales, la longitud del substring común es la longitud del substring común anterior + 1
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // Actualizamos maxLength y endIndex si encontramos un substring común más largo
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            } else {
                // Si los caracteres no son iguales, la longitud del substring común es 0
                dp[i][j] = 0;
            }
        }
    }

    // Extraemos el substring común más largo
    if (maxLength == 0) {
        return ""; // No se encontró ningún substring común
    }
    return str1.substr(endIndex - maxLength + 1, maxLength);
}

int main() {
    // Probamos la función.
    string str1 = "abcdaf";
    string str2 = "zbcdf";
    string lcs = longestCommonSubstring(str1, str2);
    cout << "Longest Common Substring: " << lcs << endl; // Imprimimos resultado
    return 0;
}