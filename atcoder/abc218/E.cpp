#include <bits/stdc++.h>
#include <atcoder/dsu>

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
	vector<tuple<int, int, int>> e(m);

	ll sum = 0;
	for (auto &[c, u, v] : e)
		cin >> u >> v >> c, --u, --v, sum += c;
	sort(all(e));

	atcoder::dsu g(n);
	for (auto [c, u, v] : e) {
		if (c <= 0 || !g.same(u, v)) {
			g.merge(u, v);
			sum -= c;
		}
	}
	cout << sum << '\n';
}
