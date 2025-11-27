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

const int MOD = 1000000007;
const int TWO_MOD_INV = 500000004;

ll power(ll a, ll n, int MOD) {
    ll res = 1;
    a %= MOD;
    while (n > 0) {
        if (n & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return res; 
}
ll power(ll a, ll n) {
    ll res = 1;
    a %= MOD;
    while (n > 0) {
        if (n & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return res; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll fcount, sumdiv, prodiv;
    fcount = sumdiv = prodiv = 1;
    ll reafcount = 1;
    vector<pair<int, int>> fact(n);
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        fact[i] = p;
        fcount = fcount * (p.second + 1) % MOD;
        sumdiv = sumdiv * (power(p.first, (p.second + 1)) - 1) % MOD * power(p.first - 1, MOD - 2) % MOD;
    }
    ll N = 1;
    for (auto it : fact) {
        N = N * power(it.first, it.second) % MOD;
    }
    cout << fcount << ' ' << sumdiv << ' ' << prodiv << endl;
    return 0;
}
// sigma (n)
// n * sigma(n) / 2
/*
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i] >> k[i];
	ll div_cnt = 1, div_sum = 1, div_prod = 1, div_cnt2 = 1;
	for (int i = 0; i < n; i++) {
		div_cnt = div_cnt * (k[i] + 1) % MOD;
		div_sum = div_sum * (expo(p[i], k[i] + 1) - 1) % MOD *
		          expo(p[i] - 1, MOD - 2) % MOD;
		div_prod = expo(div_prod, k[i] + 1) *
		           expo(expo(p[i], (k[i] * (k[i] + 1) / 2)), div_cnt2) % MOD;
		div_cnt2 = div_cnt2 * (k[i] + 1) % (MOD - 1);
	}
	cout << div_cnt << ' ' << div_sum << ' ' << div_prod;
	return 0;
}
 */
