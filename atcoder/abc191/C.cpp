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

const int N = 20;
char s[N][N];

int cnt(int h, int w) {

	// rep(i, 0, h) {
	// 	rep(j, 0, w) {
	// 		cerr << s[i][j];
	// 	}
	// 	cerr << '\n';
	// }
	// cerr << '\n';

	int res = 0;
	rep(i, 1, h) {
		int cur = 0;
		for (int j = 0, k = 0; j < w; j = k) {
			if (s[i - 1][j] != '.' || s[i][j] != '#') {
				++k;
				continue;
			}
			while (k < w && s[i - 1][k] == '.' && s[i][k] == '#') ++k;
			++cur;
		}
		res += cur;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

int h, w;
	cin >> h >> w;
	char g[N][N];
	rep(i, 0, h) rep(j, 0, w) cin >> g[i][j];

	int ans = 0;
	rep(i, 0, h) rep(j, 0, w) s[i][j] = g[i][j];
	ans += cnt(h, w);
	rep(i, 0, h) rep(j, 0, w) s[h - i - 1][j] = g[i][j];
	ans += cnt(h, w);
	rep(i, 0, h) rep(j, 0, w) s[j][i] = g[i][j];
	ans += cnt(w, h);
	rep(i, 0, h) rep(j, 0, w) s[w - j - 1][i] = g[i][j];
	ans += cnt(w, h);
	cout << ans;
}