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
    vector <bool> B(n + 1, false);
    B[0] = true;
    for (int i = 0; i < n - 1; i++) {
        int t;
        cin >> t;
        B[t] = true;
    }
    for (int i = 0; i < n + 1; i++) {
        if (B[i] == false) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}