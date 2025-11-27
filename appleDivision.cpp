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
#include <climits>

typedef long long ll;
typedef long double ld;

using namespace std;
using namespace std::chrono;

// currSum, sum - currSum
#define inf 1e18 - 2

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll sum = 0;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = inf;
    for (int i = 1; i < (1 << n); i++) {
        ll currSum = 0;
        int count = 0;
        int j = i;
        while (j) {
            if (j & 1) {
                currSum += a[count];
            }
            j >>= 1;
            count++;
        }
        ll diff = sum - currSum - currSum;
        diff = abs(diff);
        ans = min(ans, diff);
    }
    cout << ans << endl;
    return 0;
}
