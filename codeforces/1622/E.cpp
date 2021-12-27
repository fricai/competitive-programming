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

void solve() {
	int n, m; cin >> n >> m;
	vector<ll> x(n);
	for (auto &a : x) cin >> a;
	vector<string> g(n);
	for (auto &row : g)
		cin >> row;

	ll mx = -1;
	vector<int> ans;
	rep(S, 0, 1 << n) {
		ll sum = 0;
		vector<ll> c(m);
		rep(i, 0, n) {
			rep(j, 0, m) {
				int x = g[i][j] == '1';
				if (S >> i & 1) c[j] -= x;
				else c[j] += x;
			}
			if (S >> i & 1) sum += x[i];
			else sum -= x[i];
		}
		vector<int> ord(m);
		iota(all(ord), 0);
		sort(all(ord), [&](int x, int y) {
				return c[x] < c[y];
				});
		vector<int> p(m);
		rep(i, 0, m) p[ord[i]] = i + 1;
		rep(i, 0, m) sum += p[i] * c[i];
		if (uax(mx, sum)) ans = move(p);
	}

	for (auto x : ans)
		cout << x << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
