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

struct P {
    ll x, y;
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

bool intersect(P p1, P p2, P p3, P p4) {
    if ((p2 - p1) * (p4 - p3) == 0) {
        if (p1.triangle(p2, p3) != 0) {
            return false;
        } 
        for (int rep = 0; rep < 2; rep++) {
            if ((max(p1.x, p2.x) < min(p3.x, p4.x)) || (max(p1.y, p2.y) < min(p3.y, p4.y))) {
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        return true;
    }
    for (int rep = 0; rep < 2; rep++) {
        long long sign1 = (p2 - p1) * (p3 - p1);
        long long sign2 = (p2 - p1) * (p4 - p1);
        if ((sign1 > 0 && sign2 > 0) || (sign1 < 0 && sign2 < 0)) {
            return false;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    return true;
}

bool segment_contains(P a, P b, P c) {
    if (a.triangle(b, c) != 0) {
        return false;
    }
    return ((min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)) && (min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n, m;
    cin >> n >> m;
    vector <P> polygon(n);
    for (int i = 0; i < n; i++) {
        polygon[i].read();
    }
    for (int rep = 0; rep < m; rep++) {
        int count = 0;
        P point;
        point.read();
        P out(point.x + 1, 1e9 + 1);
        bool is_on_boundary = false;
        for (int i = 0; i < n; i++) {
            int j = (i == n - 1 ? 0 : i + 1);
            if (segment_contains(polygon[i], polygon[j], point)) {
                is_on_boundary = true;
                break;
            }
            if (intersect(point, out, polygon[i], polygon[j])) {
                count++;
            }
        }
        if (is_on_boundary) {
            cout << "BOUNDARY" << '\n';
        }
        else if (count % 2 == 0) {
            cout << "OUTSIDE" << '\n';
        }
        else {
            cout << "INSIDE" << '\n';
        }
    }
    return 0;
}