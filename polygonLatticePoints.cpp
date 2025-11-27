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

// half area
ll area(vector <P>& a, int n) {
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i] * a[i + 1];
    }
    sum += a[n - 1] * a[0];
    return abs(sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n;
    cin >> n;
    vector <P> polygon(n);
    for (int i = 0; i < n; i++) {
        polygon[i].read();
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int j = (i == n - 1 ? 0 : i + 1);
        P diff = polygon[j] - polygon[i];
        int g = gcd(abs(diff.x), abs(diff.y));
        ans += g;
    }
    ll a = area(polygon, n); 
    cout << (a - ans + 2) / 2 << ' ' << ans << '\n';
    return 0;

}