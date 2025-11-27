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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUll);
    string str;
    cin >> str;
    int n = str.length();
    int left, count;
    left = count = 0;
    for (int i = 0; i < n; i++) {
        int curr = 0;
        while (str[i] == str[i + 1] && i < n) {
            curr++;
            i++;
        }
        curr++;
        count = max(count, curr);
    }
    cout << count << '\n';
    return 0;
}