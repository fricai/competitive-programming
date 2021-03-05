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

const int N = 2500 + 5;
bitset<N> g[N];
int a[N][N];
pair<int, pair<int, int>> c[N * N];

bool solve() {
	int n; cin >> n;
	rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
	
	rep(i, 0, n) if (a[i][i] != 0) return false;
	rep(i, 0, n) rep(j, 0, i) if (a[i][j] != a[j][i]) return false;

	int cnt = 0;
	rep(i, 0, n) rep(j, 0, n) c[cnt++] = {a[i][j], {i, j}};
	sort(c, c + cnt, greater<>());
	
	for (int i = 0, j = 0; i < cnt; i = j) {
		while (j < cnt && c[i].first == c[j].first) ++j;
		rep(k, i, j) {
			auto [x, y] = c[k].second;
			g[x][y] = 1;
		}
		rep(k, i, j) {
			auto [x, y] = c[k].second;
			if ((g[x] | g[y]).count() < n) return false;
		}
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << (solve() ? "MAGIC" : "NOT MAGIC");
}