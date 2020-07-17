#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

string s;

int f(int l, int r, char c) {
	if (r - l == 1) return s[l] != c;
	int L = 0, R = 0, m = l + r >> 1;
	rep(i, l, m) if (s[i] != c) ++L;
	rep(i, m, r) if (s[i] != c) ++R;
	return min(L + f(m, r, c + 1), f(l, m, c + 1) + R);
}

int solve() {
	int n; cin >> n >> s;
	return f(0, n, 'a');
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}