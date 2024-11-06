#include <iostream>

using namespace std;

int main(){

	int64_t n; cin >> n;

	int64_t sum = 0;
	int64_t temp;
	for(int i=0;i<n;i++){
		cin >> temp;
		sum += temp;
	}
	cout << (((n+1)*n)/2)-sum << endl;

	return 0;
}
