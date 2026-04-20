#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;
using i128 = __int128_t;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

ostream& operator<<(ostream& os, __int128 x) {
    if (x == 0) return os << "0";
    if (x < 0) {
        os << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

i128 solve(vector<int>& a) {
    int n = a.size();
    int l, r;
    l = 0;
    r = n - 1;
    i128 c = n - 1;
    i128 sum = 0;
    while (l <= r) {
        sum += c * (i128)(a[r] - a[l]);
        c -= 2;
        l++;
        r--;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << solve(x) + solve(y) << '\n';
    return 0;
}