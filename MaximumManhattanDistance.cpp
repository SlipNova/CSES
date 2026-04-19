#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll minS = LLONG_MAX, maxS = LLONG_MIN;
    ll minD = LLONG_MAX, maxD = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        ll s = x + y;
        ll d = x - y;
        minS = min(minS, s);
        maxS = max(maxS, s);
        minD = min(minD, d);
        maxD = max(maxD, d);
        cout << max(maxS - minS, maxD - minD) << '\n';
    }
    return 0;
}