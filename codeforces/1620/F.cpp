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

constexpr int inf = 1e9;

void solve() {
	int n; cin >> n;
	vector<int> p(n);
	for (auto &x : p)
		cin >> x;
	p.insert(begin(p), -inf);

	vector<array<bool, 2>> par(n + 1);
	array<int, 2> dp;
	fill(all(dp), -inf);

	for (int i = 1; i <= n; ++i) {
		array<int, 2> nxt;
		fill(all(nxt), inf);

		for (int x = -p[i], j = 0; j < 2; ++j, x = -x) {
			if (x > -p[i - 1] && uin(nxt[j], dp[0]))
				par[i][j] = 0;
			if (x > dp[0] && uin(nxt[j], -p[i - 1]))
				par[i][j] = 0;
			if (x > +p[i - 1] && uin(nxt[j], dp[1]))
				par[i][j] = 1;
			if (x > dp[1] && uin(nxt[j], +p[i - 1]))
				par[i][j] = 1;
		}

		dp = move(nxt);
	}

	if (min(dp[0], dp[1]) > n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	vector<int> res;
	for (int i = n, state = dp[1] <= n; i > 0; --i) {
		if (state) res.push_back(+p[i]);
		else res.push_back(-p[i]);
		state = par[i][state];
	}

	reverse(all(res));
	for (auto x : res)
		cout << x << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
