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

void solve() {
    int n;
    cin >> n;
    unordered_map <int, int> mp = factors(n);
    ll prod = 1;
    for (auto it: mp) {
        prod *= (it.second + 1);
    } 
    cout << prod << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}