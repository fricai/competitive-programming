#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;

	vector<int> a(n + m + 1), c(n + m + 1);
	for (int i = 1; i <= n + m; ++i) {
		a[i] = a[i - 1] + (s[i - 1] == '1');
		c[i] = c[i - 1] + (t[i - 1] == '1');
	}

	for (int i = 1; i <= n + m; ++i) {
		if (a[i] > c[i]) swap(a[i], c[i]);
	}

	int ans = 0;
	for (int p : {0, 1}) {
		if (p < a[1] || p > c[1])
			continue;

		int beauty = 0;
		int cur = p;
		for (int i = 2; i <= n + m; ++i) {
			if (a[i] <= cur + p && cur + p <= c[i]) {
				++beauty;
			} else p ^= 1;
			cur += p;
		}

		uax(ans, beauty);
	}

	cout << ans << '\n';
}
