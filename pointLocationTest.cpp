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
// (ai + bj) * (xi + yj) = (ay - bx) k
// 4 2
// 3 0
void solve(ll x, ll y, ll a, ll b) {
    ll ans = (a * y) - (b * x);
    if (ans == 0) {
        cout << "TOUCH";
    }
    else if (ans > 0) {
        cout << "RIGHT";
    }
    else {
        cout << "LEFT";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int tt;
    cin >> tt;
    while (tt--) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        x2 -= x1;
        y2 -= y1;
        x3 -= x1;
        y3 -= y1;
        solve(x2, y2, x3, y3);
    }
    return 0;
}