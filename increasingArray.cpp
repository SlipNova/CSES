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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n;
    cin >> n;
    vector <int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
            ans += a[i] - a[i + 1];
            a[i + 1] = a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}