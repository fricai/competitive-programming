#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define ff first
#define ss second

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using pll = pair<ll, ll>;

constexpr int K = 1 << 17, N = 1 << 7;
constexpr int M = 1e9 + 7;
int f[N][K], s[N][K], a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t; cin >> n >> t;
	rep(i, 0, n) cin >> a[i];
	f[0][0] = 1;
	rep(i, 0, n) {
		for (int k = 0; k <= t; ++k)
			s[i][k + 1] = (f[i][k] + s[i][k]) % M;
		for (int k = 0; k <= t; ++k)
			f[i + 1][k] = (s[i][k + 1] - s[i][max(0, k - a[i])]) % M;
	}
	if (f[n][t] < 0) f[n][t] += M;
	cout << f[n][t];
}