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

int L(ll n, ll seed) {
    ll ans = 0;
    ll k = seed;
    while (n >= seed) {
        ans += n / seed;
        seed *= k;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n;
    cin >> n;
    int b = L(n, 5);
    cout << b << endl;
    return 0;
}