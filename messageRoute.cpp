#include <bits/stdc++.h> 

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <pair <int, int>> E(m);
	for (int i = 0; i < m; i++) {
		pair <int, int> p;
		cin >> p.first >> p.second;
		E[i] = p;
	}
	cout << "hello World" << endl;
	return 0;
}