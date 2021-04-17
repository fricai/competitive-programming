#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n; cin >> n;
	string s[3];
	rep(b, 0, 3) cin >> s[b];

	int z[3];
	rep(b, 0, 3)
		z[b] = accumulate(all(s[b]), 0, [&](int x, char c) { return x + (c != '1');});

	auto f = [](string s, string t, char c) {
		int i = 0, j = 0;
		while (i < sz(s) && j < sz(t)) {
			if (s[i] != t[j]) {
				cout << c;
				if (s[i] == c) ++i;
				else ++j;
			} else cout << s[i], ++i, ++j;
		}
		while (i < sz(s)) cout << s[i++];
		while (j < sz(t)) cout << t[j++];
		cout << '\n';
	};

	rep(i, 0, 3)
		rep(j, 0, i)
			if (z[i] <= n) {
				if (z[j] <= n) return f(s[i], s[j], '0');
			} else if (z[j] > n) return f(s[i], s[j], '1');
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}