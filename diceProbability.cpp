#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};

vector<double> mult(vector<double>& a, vector<double>& b) {
    vector<double> c(a.size() + b.size() - 1, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i + j] += a[i] * b[j]; 
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    vector<double> p(7, 0);
    for (int i = 1; i < 7; i++) {
        p[i] = 1;
    }
    vector<double> ans(1, 1);
    int k = n;
    while (n--) {
        ans = mult(p, ans);
    }
    double val = 0;
    for (int l = a; l <= b && l < ans.size(); l++) {
        val += ans[l];
    }
    val /= pow(6, k);
    cout << fixed << setprecision(6) << val << '\n';
    return 0;
}