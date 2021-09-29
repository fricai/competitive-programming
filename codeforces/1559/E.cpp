#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


constexpr int mod = 998244353;
void add(int &x, int y) {
	x += y;
	if (mod <= x)
		x -= mod;
}
void sub(int &x, int y) {
	x -= y;
	if (x < 0)
		x += mod;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> l(n), r(n);
	rep(i, 0, n) cin >> l[i] >> r[i], ++r[i];

	auto f = [&](int d) {
		vector<int> f(m / d + 1, 1);
		rep(i, 0, n) {
			vector<int> g(m / d + 1, 0);
			int L = (l[i] + d - 1) / d, R = (r[i] + d - 1) / d;
			for (int x = 0; x <= m / d; ++x) {
				if (x - L >= 0)
					add(g[x], f[x - L]);
				if (x - R >= 0)
					sub(g[x], f[x - R]);
			}
			for (int x = 1; x <= m / d; ++x)
				add(g[x], g[x - 1]);
			f = move(g);
		}
		return f.back();
	};

	vector<int> mu(m + 1), lp(m + 1);
	mu[1] = 1;
	for (int p = 2; p <= m; ++p) {
		if (lp[p] == 0) {
			for (int q = p; q <= m; q += p)
				lp[q] = p;
		}
		ll x = lp[p];
		x *= x;
		if (p % x == 0)
			mu[p] = 0;
		else
			mu[p] = -mu[p / lp[p]];
	}

	int ans = 0;
	for (int d = 1; d <= m; ++d) {
		if (mu[d] == 0)
			continue;
		if (mu[d] > 0)
			add(ans, f(d));
		else
			sub(ans, f(d));
	}
	cout << ans << '\n';
}
