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

const int mod = 1e9 + 7;

int pow(ll a, int n, int mod) {
    if (n == 0) return 0;
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    } 
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n;
    cin >> n;
    int k = pow(2, n, mod);
    cout << k << '\n';
    return 0;
}