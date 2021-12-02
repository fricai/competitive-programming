#include <bits/stdc++.h>
#include <atcoder/maxflow>

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

constexpr ll inf = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	ll ans = 0;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans += max(0, a[i]);
	}

	atcoder::mf_graph<ll> g(n + 2);
	int s = 0, t = n + 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < 0)
			g.add_edge(s, i, -a[i]);
		else
			g.add_edge(i, t, a[i]);
		for (int j = i + i; j <= n; j += i) {
			g.add_edge(i, j, inf);
		}
	}

	cout << ans - g.flow(s, t) << '\n';
}
