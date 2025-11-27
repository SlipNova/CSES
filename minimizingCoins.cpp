#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <limits>
#include <climits>

typedef long long ll;
using namespace std;

const ll inf = llONG_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> dp(x + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0 && dp[i - a[j]] != inf) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    cout << (dp[x] == inf ? -1 : dp[x]) << '\n';
    return 0;
}
