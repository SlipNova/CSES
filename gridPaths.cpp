#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
using namespace std::chrono;

const int mod = 1e9 + 7;

int solve(vector <string>& grid) {
    int n = grid.size();
    vector <vector <int>> dp(n, vector <int> (n, 0));
    dp[0][0] = (grid[0][0] == '.' ? 1 : 0);
    for (int row = 1; row < n; row++) {
        if (grid[row][0] == '*') {
            dp[row][0] = 0;
        }
        else {
            dp[row][0] = dp[row - 1][0];
        }
                                
    }
    for (int col = 1; col < n; col++) {
        if (grid[0][col] == '*') {
            dp[0][col] = 0;
        }
        else {
            dp[0][col] = dp[0][col - 1];
        }

    }
    for (int row = 1; row < n; row++)  { 
        for (int col = 1; col < n; col++) {
            if (grid[row][col] == '*') {
                dp[row][col] = 0;
            }
            else {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
                dp[row][col] %= mod;
            }
        }
    }
    return dp[n - 1][n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);      
    int n;
    cin >> n;
    vector <string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    cout << solve(grid) << endl;
	return 0;
}

