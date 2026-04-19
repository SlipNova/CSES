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

const int Mod = 1000000007;

int solve(ll a, ll n, int mod) {
    if (n == 0) {
        return 1;
    }
    ll res = (ll) 1;
    while (n) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return (int) res;
}

void doo(ll a, ll b, ll c) {
    int k = solve(b, c, Mod - 1);
    cout << solve(a, k, Mod) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        ll a, b, c;
        cin >> a >> b >> c;
        doo(a, b, c);
    }
    return 0;
}