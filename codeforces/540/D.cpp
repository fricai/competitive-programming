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

const int N = 1 << 7;
ld dp[N][N][N];

ld f(int r, int s, int p) {
	if (r <= 0) return 0;
	if (s == 0 && p == 0) return 1;
	if (dp[r][s][p] > -0.99) return dp[r][s][p];

	auto &res = dp[r][s][p];
	res = 0;
	ld mult = p * r + r * s + s * p;
	if (r > 0) res += r * p * f(r - 1, s, p);
	if (s > 0) res += s * r * f(r, s - 1, p);
	if (p > 0) res += p * s * f(r, s, p - 1); 
	return res /= mult;
}

ld g(int r, int s, int p) {
	rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) dp[i][j][k] = -1;
	return f(r, s, p);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int r, s, p; cin >> r >> s >> p;
	cout << fixed << setprecision(12) << g(r, s, p) << ' ' << g(s, p, r) << ' ' << g(p, r, s) << '\n';
}