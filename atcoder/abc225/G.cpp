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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, c; cin >> h >> w >> c;
	vector a(h, vector<int>(w));

	ll sum = 0;
	for (auto &v : a)
		for (auto &x : v)
			cin >> x, sum += x;

	auto get = [&](int i, int j) { return w * i + j; };

	int s = h * w, t = s + 1;
	atcoder::mf_graph<ll> g(t + 1);

	rep(i, 0, h)
		rep(j, 0, w) {
			int u = get(i, j);
			g.add_edge(s, u, a[i][j]);

			if (i == 0 || j == 0)
				g.add_edge(u, t, c);
			else {
				g.add_edge(u, t, 0);
				g.add_edge(u, get(i - 1, j - 1), c);
			}

			if (i == 0 || j + 1 == w)
				g.add_edge(u, t, c);
			else {
				g.add_edge(u, t, 0);
				g.add_edge(u, get(i - 1, j + 1), c);
			}
		}


	cout << sum - g.flow(s, t) << '\n';
}
