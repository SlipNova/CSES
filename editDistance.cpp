
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <numeric>
#include <iomanip>
#include <stdexcept>

typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;

using namespace std;

int editDistance(const string& one, const string& two) {
    int m = one.length();
    int n = two.length();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1));
    for (int col = 0; col <= n; col++) {
        dp[0][col] = col;
    }
    for (int row = 0; row <= m; row++) {
        dp[row][0] = row;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (one[i - 1] == two[j - 1] ? 0 : 1);
            dp[i][j] = min({dp[i - 1][j - 1] + cost, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
        }
    }
    return dp[m][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string one, two;
    cin >> one >> two;
    cout << editDistance(one, two) << endl;
    return 0;
}


