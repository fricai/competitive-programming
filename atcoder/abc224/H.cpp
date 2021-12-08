#include <bits/stdc++.h>
#include <atcoder/mincostflow>

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
	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	vector c(n, vector(m, 0));
	rep(i, 0, n)
		rep(j, 0, m)
			cin >> c[i][j];

	constexpr int C = 100, F = 10;
	int s = n + m, t = s + 1;
	atcoder::mcf_graph<int, int> g(t + 1);
	rep(i, 0, n) g.add_edge(s, i, a[i], 0);
	rep(i, 0, m) g.add_edge(i + n, t, b[i], 0);

	rep(i, 0, n)
		rep(j, 0, m)
			g.add_edge(i, j + n, F, C - c[i][j]);

	auto [flow, val] = g.flow(s, t);
	cout << C * flow - val << '\n';
}
