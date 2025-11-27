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

vector <int> _convert(vector <string>& S) {
    vector <int> sol;
    int n = S.size();
    for (int i = 0; i < n; i++) {
        int k = 0;
        int len = S[i].length();
        int two = 1;
        for (int j = len - 1; j >= 0; j--) {
            k += two * (S[i][j] - '0');
            two *= 2;
        }
        sol.push_back(k);
    }
    return sol;
}

vector <string> grayCode(vector <string>& sol, int n) {
    if (n == 1) {
        sol.push_back("0");
        sol.push_back("1");
        return sol;
    }
    vector <string> oneless = grayCode(sol, n - 1);
    vector <string> res;
    for (int i = 0; i < (int)oneless.size(); i++) {
        res.push_back("0" + oneless[i]);
    }
    reverse(oneless.begin(), oneless.end());
    for (int i = 0; i < (int)oneless.size(); i++) {
        res.push_back("1" + oneless[i]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <string> S;
    vector <string> R = grayCode(S, n);
    for (int i = 0; i < (int) R.size(); i++) {
        cout << R[i] << '\n';
    }
    return 0;
}