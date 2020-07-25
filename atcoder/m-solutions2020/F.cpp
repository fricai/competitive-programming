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

const int N = 1 << 18, inf = 1e9;
char dir[N];
int x[N], y[N];

#define f first
#define s second

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	map<int, vector<pair<int, char>>> diagl, diagr, horiz, vert;
	rep(i, 0, n) {
		cin >> x[i] >> y[i] >> dir[i];
		x[i] *= 10;
		y[i] *= 10;
		diagl[x[i] + y[i]].eb(x[i], dir[i]);
		diagr[x[i] - y[i]].eb(x[i], dir[i]);
		horiz[y[i]].eb(x[i], dir[i]);
		vert[x[i]].eb(y[i], dir[i]);
	}

	int ans = inf + 1;
	trav(z, diagl) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (
				(v[i].s == 'R' && v[i + 1].s == 'U') ||
				(v[i].s == 'D' && v[i + 1].s == 'L')
			)
				ckmin(ans, v[i + 1].f - v[i].f);
	}

	trav(z, diagr) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (
				(v[i].s == 'U' && v[i + 1].s == 'L') ||
				(v[i].s == 'R' && v[i + 1].s == 'D')
			)
				ckmin(ans, v[i + 1].f - v[i].f);
	}

	trav(z, horiz) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (v[i].s == 'R' && v[i + 1].s == 'L')
				ckmin(ans, (v[i + 1].f - v[i].f) / 2);
	}
	
	trav(z, vert) {
		auto &v = z.s;
		sort(all(v));
		rep(i, 0, sz(v) - 1)
			if (v[i].s == 'U' && v[i + 1].s == 'D')
				ckmin(ans, (v[i + 1].f - v[i].f) / 2);
	}
	
	if (ans > inf) cout << "SAFE";
	else cout << ans;
}