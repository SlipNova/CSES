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

const int mod = 1000000007;

int solve(ll a, ll n) {
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int tt;
    cin >> tt;
    while (tt--) {
        ll a, n;
        cin >> a >> n;
        cout << solve(a, n) << '\n';
    }
    return 0;
}