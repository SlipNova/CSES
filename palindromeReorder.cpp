#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solveAgain() {
    string str;
    cin >> str;
    int n = str.length();
    unordered_map<char, int> mp;
    for (char ch : str) {
        mp[ch]++;
    }
    vector<pair<char, int>> freq;
    int oddCount = 0;
    char oddChar = '\0';
    for (const auto& it : mp) {
        if (it.second % 2 == 1) {
            oddCount++;
            oddChar = it.first;
            if (oddCount > 1) {
                cout << "NO SOLUTION" << endl;
                return;
            }
        }
        freq.push_back(it);
    }
    string half, middle;
    for (const auto& p : freq) {
        if (p.second % 2 == 1) {
            middle += p.first;
        }
        half += string(p.second / 2, p.first);
    }
    string sol = half;
    if (!middle.empty()) {
        sol += middle;
    }
    reverse(half.begin(), half.end());
    sol += half;
    cout << sol << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solveAgain();
    return 0;
}
