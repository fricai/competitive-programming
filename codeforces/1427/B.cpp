#include <bits/stdc++.h>
using namespace std;

int score(string s) {
    bool fst = 1;
    int res = 0;
    for (char c : s) {
        if (c != 'W') fst = 1;
        else {
            if (fst) res += 1, fst = 0;
            else res += 2;
        }
    }
    return res;
}

int solve() {
    int n, k; cin >> n >> k;
    vector<tuple<int, int, int>> v;
    string s; cin >> s;
    for (int i = 0, j = 0; i < n; i = j) {
        if (s[i] == 'W') { ++j; continue; }
        while (j < n && s[j] == 'L') ++j;
        v.emplace_back(0 < i && j < n ? j - i : 1 << 25, i, j);
    }
    sort(begin(v), end(v));
    for (auto [_, i, j] : v)
        if (i)
            for (int r = i; r < j && k > 0; ++r, --k)
                s[r] = 'W';
        else
            for (int r = j; r > i && k > 0; --r, --k)
                s[r - 1] = 'W';
    return score(s);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}