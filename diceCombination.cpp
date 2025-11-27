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

#define mod 1000000007

using namespace std;
using namespace std::chrono;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n;
    cin >> n;
    vector <ll> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    for (int i = 7; i < n + 1; i++) {
        dp[i] += dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6];
        dp[i] %= mod;
    }
    cout << dp[n] << '\n';
    return 0;
}