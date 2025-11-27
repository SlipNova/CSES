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

const int MOD = 1e9 + 7;
const int TWO_MOD_INV = 500000004;

unordered_map <int, int> factors(int n) {
    unordered_map <int, int> mp;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            mp[x]++;
            n /= x;
        }
    }
    if (n > 1) mp[n]++;
    return mp;
}

ll power(ll a, ll n, int mod) {
    if (n == 0) return 1;
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
    return res % mod;
}

int S(int num, int n) {
    ll sum = 1;
    int k = num;
    int count = 1;
    while (count <= n) {
        sum += num;
        sum %= MOD;
        num = num * k;
        num %= MOD;
        count++;
    }
    return (int) sum;
}

int help(ll n) {
    unordered_map <int, int> mp = factors(n);
    ll prod = 1;
    for (auto it: mp) {
        prod *= S(it.first, it.second);
        prod %= MOD;
    } 
    return prod;
}


void solve1() {
    ll n;
    cin >> n;
    ll summ = 0;
    for (int i = 1; i <= n; i++) {
        summ += help(i);
        summ %= MOD;
    }
    cout << summ << endl;
}

// summation d * (n / d) for d in [1, n]
void solve2() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int d = 1; d <= n; d++) {
        ans += d * (n / d);
    }
    cout << ans << endl;
}

ll total_sum(ll start, ll end) {
    return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) * TWO_MOD_INV % MOD);
}

void solve() {
    ll n;
    cin >> n;
    ll d = 1;
    ll sum = 0;
    while (d <= n) {
        ll q = n / d;
        ll last_same = n / q;
        sum = (sum + q * total_sum(d, last_same)) % MOD;
        d = last_same + 1;
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}