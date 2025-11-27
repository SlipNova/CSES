#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {
    auto check = [&] (int x) {
        x %= 4;
        return x;
    };
    if (check(n) == 2 || check(n) == 1) {
        cout << "NO" << endl;
        return;
    }
    vector<int> subset1, subset2;
    long long need = (n * (n + 1)) / 4; 
    if (check(n) == 0) {
        for (int i = 1; i <= n; i++) {
            if (check(i) == 1 || check(i) == 0) {
                subset1.push_back(i);
            }
            else {
                subset2.push_back(i);
            }
        }
    }
    else {
        subset1.push_back(1);
        subset1.push_back(2);
        subset2.push_back(3);
        for (int i = 4; i <= n; i++) {
            if (check(i) == 0 || check(i) == 3) {
                subset1.push_back(i);
            }
            else {
                subset2.push_back(i);
            }
        }
    }
    cout << "YES" << '\n';
    cout << subset1.size() << '\n';
    for (int i = 0; i < subset1.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << subset1[i];
    }
    cout << '\n';
    cout << subset2.size() << '\n';
    for (int i = 0; i < subset2.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << subset2[i];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    solve(n);
    return 0;
}
