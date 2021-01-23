#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct op {
	ll x[3][3];
	op() { rep(i, 0, 3) rep(j, 0, 3) x[i][j] = 0; }
	op(vector<vector<ll>> v) {
		rep(i, 0, 3) rep(j, 0, 3) x[i][j] = v[i][j];
	}
	op operator*(const op &a) {
		op res;
		rep(i, 0, 3)
			rep(j, 0, 3)
				rep(k, 0, 3)
					res.x[i][j] += x[i][k] * a.x[k][j];
		return res;
	}
};

op flip_about_x(ll p) {
	return op({
		{-1, 0, 2 * p},
		{0, 1, 0},
		{0, 0, 1}
	});
}

op flip_about_y(ll p) {
	return op({
		{1, 0, 0},
		{0, -1, 2 * p},
		{0, 0, 1}
	});
}

op rot_cw(
	{
		{0, 1, 0},
		{-1, 0, 0},
		{0, 0, 1}
	}
);

op rot_ccw(
	{
		{0, -1, 0},
		{1, 0, 0},
		{0, 0, 1}
	}
);

op id(
	{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	}
);

const int N = 1 << 18;

pair<ll, ll> stuff(op a, ll x, ll y) {
	// cerr << a.x[0][0] << ' ' << a.x[0][1] << ' ' << a.x[0][2] << '\n';
	// cerr << a.x[1][0] << ' ' << a.x[1][1] << ' ' << a.x[1][2] << '\n';
	return {a.x[0][0] * x + a.x[0][1] * y + a.x[0][2], a.x[1][0] * x + a.x[1][1] * y + a.x[1][2]};
}

int x[N], y[N];
op t[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m; cin >> m;
	rep(i, 0, m) cin >> x[i] >> y[i];

	int n; cin >> n;
	t[0] = id;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (x == 1) t[i] = rot_cw;
		else if (x == 2) t[i] = rot_ccw;
		else {
			int p; cin >> p;
			if (x == 3) t[i] = flip_about_x(p);
			else t[i] = flip_about_y(p);
		}
		t[i] = t[i] * t[i - 1];
	}


	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b; --b;
		auto [u, v] = stuff(t[a], x[b], y[b]);
		cout << u << ' ' << v << '\n';
	}
}