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

const int N = 1 << 11;
int s[N][N], t[N][N];

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m, k; cin >> n >> m >> k;

	vector<pair<int, int>> it(m);
	for (auto &[l, r] : it) { cin >> l >> r; --l; }
	sort(all(it), [&](auto a, auto b) {
		auto [x, y] = a;
		auto [l, r] = b;
		return x + y < l + r;
	});

	// let s[i][x] = cost if all intervals [i, m) go to [x, x + k)
	for (int i = m; i--; ) {
		auto [l, r] = it[i];
		for (int x = 0; x + k <= n; ++x)
			s[i][x] = s[i + 1][x] + max(0, min(r, x + k) - max(l, x));
	}

	// let t[i][x] = cost if all intervals [0, i) for to [x, x + k)
	for (int i = 0; i < m; ++i) {
		auto [l, r] = it[i];
		for (int x = 0; x + k <= n; ++x)
			t[i + 1][x] = t[i][x] + max(0, min(r, x + k) - max(l, x));
	}

	auto d = [&](int i, int x) {
		auto [l, r] = it[i];
		return abs(l + r - k - 2 * x);
	};

	int ans = 0;
	for (int x = 0; x + k <= n; ++x) {
		int j = 0;
		for (int y = x; y + k <= n; ++y) {
			while (j < m && d(j, x) < d(j, y)) ++j; // [0, j) goes to x that means d(j, x) >= d(j, y) and d(j - 1, x) < d(j - 1, y)
			ckmax(ans, t[j][x] + s[j][y]);
		}
	}

	cout << ans;
}