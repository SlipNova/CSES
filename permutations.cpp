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


void solve(int n) {
    int k = 1;
    for (int i = 1; i <= n; i++) {
        if (i != n) {
            cout << k << ' ';
        }
        else {
            cout << k << '\n';
        }
        k += 2;
        k %= n;
        if (k == 0) k = n;
        if (k == 1 && i > 1) {
            k += 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n;
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << '\n';
    }
    else if (n == 4) {
        cout << "2 4 1 3" << '\n';
    }
    else {
        solve(n);
    }
    return 0;
}