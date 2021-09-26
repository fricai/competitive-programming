#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<ll> x(n), y(n), c(n);
	rep(i, 0, n) cin >> x[i] >> y[i] >> c[i];

	map<pair<int, int>, vector<tuple<int, int, int>>> m;
	rep(i, 0, n) {
		rep(j, 0, i) {

			int Y = y[i] - y[j];
			int X = x[i] - x[j];
			int g = gcd(X, Y);
			X /= g;
			Y /= g;
			if ((Y == 0 && X < 0) || Y < 0) X = -X, Y = -Y, g = -g;

			m[pair(X, Y)].emplace_back(i, j, g);
		}
	}

	ll ans = -1;
	for (auto &[_, v] : m) {
		map<pair<ll, ll>, vector<pair<int, int>>> cur;
		for (auto [i, j, g] : v) {
			ll p = (x[i] * x[i] + y[i] * y[i]) - (x[j] * x[j] + y[j] * y[j]);
			ll q = 2 * g;
			ll t = gcd(p, q);
			p /= t;
			q /= t;
			if ((q == 0 && p < 0) || q < 0) p = -p, q = -q;
			cur[pair(p, q)].emplace_back(i, j);
		}
		for (auto &[__, w] : cur) {
			map<pair<ll, ll>, ll> fin;
			for (auto [i, j] : w) {
				uax(fin[pair(x[i] + x[j], y[i] + y[j])], c[i] + c[j]);
			}
			if (sz(fin) <= 1)
				continue;
			ll mx = 0, smx = 0;
			for (auto [_, z] : fin) {
				if (mx <= z) {
					smx = mx;
					mx = z;
				} else if (smx <= z) {
					smx = z;
				}
			}
			uax(ans, mx + smx);
		}
	}

	cout << ans << '\n';
}
