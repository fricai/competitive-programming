#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int mod = 998244353;
using mint = atcoder::static_modint<mod>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, k; cin >> h >> w >> k;

	vector f(k + 1, array<array<mint, 2>, 2>());
	f[0][1][1] = 1;
	for (int i = 0; i < k; ++i) {
		f[i + 1][0][0] = (h - 2) * f[i][0][0] + f[i][1][0] + (w - 2) * f[i][0][0] + f[i][0][1];
		f[i + 1][0][1] = (h - 2) * f[i][0][1] + f[i][1][1] + (w - 1) * f[i][0][0];
		f[i + 1][1][0] = (h - 1) * f[i][0][0] + (w - 2) * f[i][1][0] + f[i][1][1];
		f[i + 1][1][1] = (h - 1) * f[i][0][1] + (w - 1) * f[i][1][0];
	}

	int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
	cout << f[k][x1 == x2][y1 == y2].val() << '\n';
}
