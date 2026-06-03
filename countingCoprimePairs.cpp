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




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int MX = *max_element(a.begin(), a.end());
    vector<int> freq(MX + 1, 0), c(MX + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    for (int i = 1; i <= MX; i++) {
        for (int d = i; d <= MX; d += i) {
            c[i] += freq[d];
        }
    }
    vector<long long> exact(MX + 1, 0);
    for (int d = MX; d >= 1; d--) {
        exact[d] = 1LL * c[d] * (c[d] - 1) / 2;
        for (int m = 2 * d; m <= MX; m += d) {
            exact[d] -= exact[m];
        }
    }
    cout << exact[1] << '\n';
    return 0;
}