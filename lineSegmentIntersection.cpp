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

void solve() {
    P p1, p2, p3, p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();
    if ((p2 - p1) * (p4 - p3) == 0) {
        if (p1.triangle(p2, p3) != 0) {
            cout << "NO" << '\n';
            return;
        } 
        for (int rep = 0; rep < 2; rep++) {
            if ((max(p1.x, p2.x) < min(p3.x, p4.x)) || (max(p1.y, p2.y) < min(p3.y, p4.y))) {
                cout << "NO" << '\n';
                return;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        cout << "YES" << '\n';
        return;
    }
    for (int rep = 0; rep < 2; rep++) {
        long long sign1 = (p2 - p1) * (p3 - p1);
        long long sign2 = (p2 - p1) * (p4 - p1);
        if ((sign1 > 0 && sign2 > 0) || (sign1 < 0 && sign2 < 0)) {
            cout << "NO" << '\n';
            return;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    cout << "YES" << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}