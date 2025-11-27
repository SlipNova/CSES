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

const int MAXX = 1000000;

void solve1(vector <int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxx = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            maxx = max(maxx,gcd(a[i], a[j]));
        }
    }
}

void solve(int n) {
    vector <int> divisors(MAXX + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        const int bound = (int) sqrt(a);
        for (int div = 1; div <= bound; div++) {
            if (a % div == 0) {
                divisors[div]++;
                if (div != a / div) {
                    divisors[a / div]++;
                }
            }
        }
    }
    for (int i = MAXX + 1; i >= 1; i--) {
        if (divisors[i] >= 2) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    int n;
    cin >> n;
    solve(n);
    return 0;
}