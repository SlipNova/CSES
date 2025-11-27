
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

// O(n^2)
int solve(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (auto it: dp) {
        cout << it << ' ';
    }
    cout << endl;
    return *max_element(dp.begin(), dp.end());
}

// O(n * log n) using binakry search
int LIS(vector<int>& a) {
    int n = a.size();
    vector<int> dp;
    for (int num: a) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
            dp.push_back(num);
        }
        else {
            *it = num;
        }
    }
    return dp.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << LIS(a) << endl; 
    return 0;
}


