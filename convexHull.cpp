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
    bool operator<(const P& b) const {
        if (x < b.x) {
            return true;
        }
        else if (x == b.x) {
            if (y < b.y) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <P> points(n);
    for (int i = 0; i < n; i++) {
        points[i].read();
    }
    sort(points.begin(), points.end());
    vector <P> hull;
    for (int rep = 0; rep < 2; rep++) {
        const int s = hull.size();
        for (P c: points) {
            while ((int) hull.size() - s >= 2) {
                P a = hull.end()[-2];
                P b = hull.end()[-1];
                if (a.triangle(b, c) <= 0) { // check if b is on left of ac 
                    break;
                }
                hull.pop_back();
            }
            hull.push_back(c);
        }
        hull.pop_back();
        reverse(points.begin(), points.end());
    }
    cout << hull.size() << '\n';
    for (P p: hull) {
        cout << p.x << ' ' << p.y << '\n';
    }
    return 0;
}