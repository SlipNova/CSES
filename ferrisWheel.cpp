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
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    int ans = 0;
    int l = 0; 
    int r = n - 1;
    while (l <= r) {
        if (w[r] + w[l] <= x) {
            l++;
            r--;
        }
        else {
            r--;
        }
        ans++;
    }
    cout << ans << '\n';
    return 0;
}