#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    auto cmp = [] (pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    };
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    int end = -1;
    for (int i = 0; i < n; i++) {
        if (end <= a[i].first) {
            ans++;
            end = a[i].second;
        }
    }
    cout << ans << '\n';
    return 0;
}