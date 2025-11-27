
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <numeric>
#include <iomanip>
#include <stdexcept>

typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;

using namespace std;

void add(vector <bool>& in, int k) {
    vector <int> pos;
    for (int i = 0; i < in.size(); i++) {
        if (in[i]) {
            pos.push_back(i + k);
        }
    }
    for (int i = 0; i < pos.size(); i++) {
        in[pos[i]] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector <bool> in(sum + 2, false);
    in[0] = true;
    for (int i = 0; i < n; i++) {
        add(in, a[i]);
    }
    vector <int> sol;
    for (int i = 1; i < in.size(); i++) {
        if (i > sum) {
            break;
        }
        if (in[i]) {
            sol.push_back(i);
        }
    }
    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << sol[i];
    }
    cout << endl;
    return 0;
}


