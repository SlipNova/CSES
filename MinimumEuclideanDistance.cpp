#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

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

ll Dist(const P& a, const P& b) {
    ll c = a.x - b.x;
    ll d = a.y - b.y;
    return c * c + d * d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        P pt;
        pt.read();
        a[i] = pt;
    }
    auto compare = [] (const P& p1, const P& p2) {
        if (p1.x == p2.x) {
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    };
    sort(a.begin(), a.end(), compare);
    set<pair<ll, ll>> box;
    ll mn = LLONG_MAX;
    int l = 0;
    for (int i = 0; i < n; i++) {
        P curr = a[i];
        while (l < i) {
            ll dx = curr.x - a[l].x;
            if (dx * dx >= mn) {
                box.erase({a[l].y, a[l].x});
                l++;
            }
            else {
                break;
            }
        }
        ll gap = sqrt((ld) mn) + 1;
        auto it1 = box.lower_bound({curr.y - gap, -INT_MAX});
        auto it2 = box.upper_bound({curr.y + gap, INT_MAX});
        for (auto it = it1; it != it2; it++) {
            P p(it -> second, it -> first);
            mn = min(mn, Dist(p, curr));
        }
        box.insert({curr.y, curr.x});
    }
    cout << mn << '\n';
    return 0;
}