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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> n >> target;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j - a[i] >= 0) {
                dp[j] += dp[j - a[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[target] << endl;
    return 0;
}