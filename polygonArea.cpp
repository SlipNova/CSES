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

struct P {
    int x, y;
    P(): x(0), y(0) {}
    P(int _x, int _y) : x(_x), y(_y) {}
    void read() {
        cin >> x >> y;
    }
    P operator- (const P& b) const {
        return P(x - b.x, y - b.y);
    }
    void operator-=(const P& b) {
        x -= b.x;
        y -= b.y;
    }
    ll operator*(const P& b) const {
        return (ll) x * b.y - (ll) y * b.x; 
    }

    ll triangle(const P& b, const P& c) const {
        return (b - *this) * (c - *this);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n;
    cin >> n;
    vector <P> a(n);
    for (int i = 0; i < n; i++) {
        a[i].read();
    }
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i] * a[i + 1];
    }
    sum += a[n - 1] * a[0];
    cout << abs(sum) << '\n';
    return 0;
}