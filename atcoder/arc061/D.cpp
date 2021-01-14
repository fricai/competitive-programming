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

set<pair<int, int>> f[10];

int h, w;

void update(int i, int j) {
	if (i <= 0 || j <= 0 || i + 2 > h || j + 2 > w) return;
	int loc = 0;
	rep(a, 1, 9) {
		auto it = f[a].find({i, j});
		if (it != end(f[a])) {
			f[a].erase(it);
			loc = a;
			break;
		}
	}
	f[loc + 1].insert({i, j});
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w;
	int n; cin >> n;
	rep(i, 0, n) {
		int a, b; cin >> a >> b;
		rep(x, 0, 3) rep(y, 0, 3) update(a - x, b - y);
	}

	int tot = 0;
	rep(i, 1, 10) tot += sz(f[i]);
	cout << 1ll * (h - 2) * (w - 2) - tot << '\n';
	rep(i, 1, 10) cout << sz(f[i]) << '\n';
}