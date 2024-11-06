#include <iostream>

using namespace std;

int DFS(int node, const vector<vector<int>> &ady){
	int MAX = 1;
	for(int next: ady[node])
		MAX = max(MAX, DFS(next, ady)+1);
	return MAX;
}

int main(){
	int n; cin >> n;
	vector<pair<int, int>> m(n);
	for(auto &p: m) cin >> p.first >> p.second;

	vector<vector<int>> ady(n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(m[i].first < m[j].first && m[i].second < m[j].second)
				ady[i].push_back(j);

	int MAX = INT_MIN;
	for(int i = 0 ; i < n; i++)
		MAX = max(MAX, DFS(i, ady));
	cout << MAX << endl;

}
