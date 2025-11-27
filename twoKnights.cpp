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

// 0 0
// 0 0

void solve(int n) {
    ll a = n;
    ll b = 4 * (n - 1) * (n - 2);
    a *= a;
    a = a * (a - 1) / 2;
    cout << a - b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    return 0;
}