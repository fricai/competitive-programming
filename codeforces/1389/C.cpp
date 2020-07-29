#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18, D = 10;
vector<int> loc[D];


int solve() {
	string s; cin >> s;
	int n = sz(s);
	rep(j, 0, D) loc[j].clear();
	rep(i, 0, n) loc[s[i] -= '0'].eb(i);
	int ans = 0;
	rep(c, 0, D) ckmax(ans, sz(loc[c]));
	rep(c, 0, D) {
		auto &a = loc[c];
		if (a.empty()) continue;
		rep(d, 0, D) {
			auto &b = loc[d];
			if (c == d || b.empty()) continue;
			int cnt = 0, i = 0, j = 0, x = sz(a), y = sz(b);
			while (true) {
				while (j < y && b[j] < a[i]) ++j;
				if (j == y) break;
				cnt += 2;
				while (i < x && a[i] < b[j]) ++i;
				if (i == x) break;
			}
			ckmax(ans, cnt);
		}
	}
	return n - ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}