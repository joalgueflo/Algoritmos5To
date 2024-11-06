#include <iostream>

using namespace std;

int main(){
	int n; cin >> n;
	vector<vector<int>> m(n, vector<int>(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> m[j][n-i-1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}


	
};


// Entrada: 
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// Salida: 
// 7 4 1
// 8 5 2
// 9 6 3


// Entrada: 
// 4
// 5 1 9 11
// 2 4 8 10
// 13 3 6 7
// 15 14 12 16
// Salids:
// 15 13 2 5
// 14 3 4 1
// 12 6 8 9
// 16 7 10 11