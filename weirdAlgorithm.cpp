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
    ll n;
    cin >> n;
    while (n != 1) {
        cout << n << ' ';
        if (n % 2 == 1) {
            n = 3 * n + 1;
        }
        else {
            n /= 2;
        }
    }
    cout << 1 << '\n';
    return 0;
}