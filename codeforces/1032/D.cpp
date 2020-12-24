#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ld inf = 1e12;
ld d[6][6];
pair<ld, ld> p[6];

ld f(ld a, ld b, ld c, ld x) { return - a * x / b - c / b; }
ld g(ld a, ld b, ld c, ld y) { return - b * y / a - c / a; }

ld dist(pair<ld, ld> a, pair<ld, ld> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b, c; cin >> a >> b >> c;
	ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;

	p[0] = {x1, y1};
	p[1] = {x2, y2};
	
	int tot = 2;
	if (b != 0) p[tot++] = {x1, f(a, b, c, x1)};
	if (b != 0) p[tot++] = {x2, f(a, b, c, x2)};
	if (a != 0) p[tot++] = {g(a, b, c, y1), y1};
	if (a != 0) p[tot++] = {g(a, b, c, y2), y2};
	rep(i, 0, tot) rep(j, 0, tot) d[i][j] = numeric_limits<ld>::infinity();
	rep(i, 0, tot) d[i][i] = 0;
	rep(i, 2, tot)
		rep(j, 2, tot)
			d[i][j] = dist(p[i], p[j]);
	rep(i, 0, 2)
		rep(j, 0, tot)
			d[i][j] = d[j][i] = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
	
	rep(k, 0, tot)
		rep(i, 0, tot)
			rep(j, 0, tot)
				ckmin(d[i][j], d[i][k] + d[k][j]);
	cout << fixed << setprecision(10) << d[0][1];
	// rep(i, 0, )
}