#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9;
#define f first
#define s second

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	map<int, vector<pair<int, char>>> RU, DL, UL, RD, RL, UD;
	rep(i, 0, n) {
		int x, y; char d;
		cin >> x >> y >> d;
		x *= 10; y *= 10;
		if (d == 'R' || d == 'U') RU[x + y].eb(x, d);
		if (d == 'D' || d == 'L') DL[x + y].eb(x, d);
		if (d == 'U' || d == 'L') UL[x - y].eb(x, d);
		if (d == 'R' || d == 'D') RD[x - y].eb(x, d);
		if (d == 'R' || d == 'L') RL[y].eb(x, d);
		if (d == 'D' || d == 'U') UD[x].eb(y, d);
	}

	int ans = inf + 1;
	trav(z, RU) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (v[i].s == 'R' && v[i + 1].s == 'U')
				ckmin(ans, v[i + 1].f - v[i].f);
	}

	trav(z, DL) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (v[i].s == 'D' && v[i + 1].s == 'L')
				ckmin(ans, v[i + 1].f - v[i].f);
	}

	trav(z, UL) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (v[i].s == 'U' && v[i + 1].s == 'L')
				ckmin(ans, v[i + 1].f - v[i].f);
	}

	trav(z, RD) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (v[i].s == 'R' && v[i + 1].s == 'D')
				ckmin(ans, v[i + 1].f - v[i].f);
	}

	trav(z, RL) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (v[i].s == 'R' && v[i + 1].s == 'L')
				ckmin(ans, (v[i + 1].f - v[i].f) / 2);
	}

	trav(z, UD) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (v[i].s == 'U' && v[i + 1].s == 'D')
				ckmin(ans, (v[i + 1].f - v[i].f) / 2);
	}

	if (ans > inf) cout << "SAFE"; else cout << ans;
}