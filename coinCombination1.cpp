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

const int mod = 1000000007;

using namespace std;
using namespace std::chrono;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n, target;
    cin >> n >> target;
    vector <int> a(n);
    vector <int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= target + 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0) {
                dp[i] += dp[i - a[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[target] << '\n';
    return 0;
}