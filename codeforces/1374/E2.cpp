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

#define int ll

const int N = 1 << 18;
pair<int, int> pa[N], pb[N], pc[N], pd[N];
int a[N], b[N], c[N], d[N];
const int inf = 1e9;

vector<ll> solve() {
	int n, m, r; cin >> n >> m >> r;

	int x = 0, y = 0, z = 0, w = 0;
	rep(i, 0, n) {
		int t, u, v; cin >> t >> u >> v;
		if ( u && !v) pa[x++] = {t, i + 1};
		if (!u &&  v) pb[y++] = {t, i + 1};
		if ( u &&  v) pc[z++] = {t, i + 1};
		if (!u && !v) pd[w++] = {t, i + 1};
	}

	if (z + x < r || z + y < r) return { };

	sort(pa, pa + x); sort(pb, pb + y);
	sort(pc, pc + z); sort(pd, pd + w);
	rep(i, 0, x) a[i] = pa[i].first;
	rep(i, 0, y) b[i] = pb[i].first;
	rep(i, 0, z) c[i] = pc[i].first;
	rep(i, 0, w) d[i] = pd[i].first;

	int i = 0, j = 0, k = 0, l = 0;

	ll ans = 0;
	while (r) {
		if (k == z) while (r && i < x && j < y) ans += a[i++] + b[j++], --r;
		else if (i == x || j == y) while (r && k < z) ans += c[k++], --r;
		else {
			if (a[i] + b[j] > c[k]) ans += c[k++];
			else ans += a[i++] + b[j++];
			--r;
		}
	}

	a[x] = b[y] = c[z] = d[w] = inf;
	if (i + j + k <= m) {
		int q = m - i - j - k;
		while (q) {
			int u = min({a[i], b[j], c[k], d[l]});
			int v = a[i] + b[j] - c[max(0ll, k - 1)];
			if (k > 0 && i < x && j < y && u > v) {
				ans += v;
				++i; ++j; --k;
			} else {
						 if (d[l] == u) ++l;
				else if (a[i] == u) ++i;
				else if (b[j] == u) ++j;
				else if (c[k] == u) ++k;
				ans += u;
			}
			--q;
		}
	} else {
		int q = i + j + k - m;
		while (q && i > 0 && j > 0 && k < z)
			ans += c[k++] - a[--i] - b[--j], --q;
		if (q) return { };
	}
	return {ans, i, j, k, l};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto v = solve();
	if (v.empty()) return cout << -1, 0;
	assert(sz(v) == 5);
	cout << v[0] << '\n';
	rep(i, 0, v[1]) cout << pa[i].second << ' ';
	rep(i, 0, v[2]) cout << pb[i].second << ' ';
	rep(i, 0, v[3]) cout << pc[i].second << ' ';
	rep(i, 0, v[4]) cout << pd[i].second << ' ';
}