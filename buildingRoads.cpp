#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <chrono>

typedef long long ll;
typedef long double ld;

using namespace std;
using namespace std::chrono;

template <typename T>
class UnionFind {
    unordered_map<T, T> parent;
    unordered_map<T, int> rank;
public:
    UnionFind() {}

    void add(const T& _ele) {
        if (parent.find(_ele) == parent.end()) {
            parent[_ele] = _ele;
            rank[_ele] = 1;
        }
    }

    T find(const T& _ele) {
        if (parent[_ele] != _ele) {
            parent[_ele] = find(parent[_ele]);
        }
        return parent[_ele];
    }

    void unite(const T& P, const T& Q) {
        T rootP = find(P);
        T rootQ = find(Q);
        if (rootP != rootQ) {
            if (rank[rootP] > rank[rootQ]) {
                parent[rootQ] = rootP;
            }
            else if (rank[rootP] < rank[rootQ]) {
                parent[rootP] = rootQ;
            }
            else {
                parent[rootQ] = rootP;
                rank[rootP] += 1;
            }
        }
    }

    vector <int> solve() {
        unordered_set <int> a;
        for (const auto& it: parent) {
            a.insert(find(it.first));
        }
        vector <int> ans;
        for (auto it: a) {
            ans.push_back(it);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> E(m);
    for (int i = 0; i < m; i++) {
        vector <int> temp(2);
        cin >> temp[0] >> temp[1];
        E[i] = temp;
    }
    UnionFind <int> uf;
    for (int i = 1; i <= n; i++) {
        uf.add(i);
    }
    for (int i = 0; i < m; i++) {
        uf.unite(E[i][0], E[i][1]);
    }
    vector <int> ans = uf.solve();
    cout << ans.size() - 1 << '\n';
    for (int i = 0; i < (int) ans.size() - 1; i++) {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }
    return 0;
}