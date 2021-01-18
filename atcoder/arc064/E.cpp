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

const int N = 1 << 10;
const double inf = 1e12;
const double eps = 1e-10;
double g[N][N], d[N];
bool vis[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<tuple<int, int, int>> v;
	int x, y;
	cin >> x >> y;
	v.emplace_back(x, y, 0);
	cin >> x >> y;
	v.emplace_back(x, y, 0);

	int n; cin >> n;
	rep(i, 0, n) {
		int x, y, r; cin >> x >> y >> r;
		v.emplace_back(x, y, r);
	}
	rep(i, 0, n + 2) {
		auto [x, y, r] = v[i];
		rep(j, 0, n + 2) {
			auto [a, b, p] = v[j];
			g[i][j] = max(0.0, hypot<double>(x - a, y - b) - r - p);
		}
		d[i] = inf;
	}
	d[0] = 0;
	rep(i, 0, n + 2) {
		int v = -1;
		rep(j, 0, n + 2) if (!vis[j] && (v == -1 || d[j] < d[v])) v = j;
		vis[v] = true;
		rep(u, 0, n + 2) ckmin(d[u], d[v] + g[u][v]);
	}
	cout << fixed << setprecision(10) << d[1];
}