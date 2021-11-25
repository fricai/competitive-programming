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

#pragma GCC optimize ("trapv") 

constexpr ll inf = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	int s = n * (m - 1), t = s + 1;
	auto f = [&](int i, int j) {
		if (j == 0)
			return s;
		if (j == m)
			return t;
		return i * (m - 1) + (j - 1);
	};

	atcoder::mf_graph<ll> g(t + 1);

	vector a(n, vector(m, 0ll));
	rep(i, 0, n) {
		rep(j, 0, m) {
			ll c;
			cin >> a[i][j] >> c;
			g.add_edge(f(i, j), f(i, j + 1), c);
			g.add_edge(f(i, j + 1), f(i, j), inf);
		}
	}

	vector w(n, vector(n, 0));
	rep(i, 0, n) {
		rep(j, i + 1, n) {
			cin >> w[i][j];
			w[j][i] = w[i][j];
		}
	}

	rep(i, 0, n) {
		rep(j, 0, n) {
			if (i == j)
				continue;

			for (int l = 0; l < m; ++l) {
				for (int r = 1; r <= m; ++r) {
					ll lo = max(a[i][r - 1], l ? a[j][l - 1] : -inf);
					ll hi = min(a[j][l], r < m ? a[i][r] : +inf);
					if (lo < hi) {
						g.add_edge(f(j, l), f(i, r), (hi - lo) * w[i][j]);
					}
				}
			}
		}
	}

	cout << g.flow(s, t) << '\n';
}
