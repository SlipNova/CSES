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

template <typename U>
class edge {
public:
    int from;
    int to;
    U cost;

    edge(int _from, int _to, U _cost) : from(_from), to(_to), cost(_cost) { };
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, start, stop;
    cin >> n >> m >> start >> stop;
    vector <edge<ld>> E;
    for (int i = 0; i < m; i++) {
        int a, b;
        ld c;
        cin >> a >> b >> c;
        edge <ld> e(a, b, c);
        E.push_back(e);
    }
    return 0;
}





