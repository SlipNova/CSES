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

void solve(ll a, ll b) {
    if (b > a) {
        swap(a, b);
    }
    if (a > 2 * b || (a + b) % 3 != 0) {
        cout << "NO" << '\n';
    }
    else {
        cout << "YES" << '\n';
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}