#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)

using ll = int64_t;
using ld = long double;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr ll inf = 2e18;
constexpr int M = 1e9 + 7;

const int N = 310;
ld dp[N][N][N];

int n;
ld E(int i, int j, int k) {
	if (i < 0 || j < 0 || k < 0) return 0;
	auto &x = dp[i][j][k];
	if (x == -1) {
		ld s = i + j + k;
		x = n / s;
		x += i * E(i - 1, j, k) / s;
		x += j * E(i + 1, j - 1, k) / s;
		x += k * E(i, j + 1, k - 1) / s;
	}
	return x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int cnt[3] = {0, 0, 0};
	rep(i, 0, n) { int a; cin >> a; --a; ++cnt[a]; }
	rep(i, 0, n + 1) rep(j, 0, n + 1) rep(k, 0, n + 1) dp[i][j][k] = -1;
	dp[0][0][0] = 0;
	cout << fixed << setprecision(18) << E(cnt[0], cnt[1], cnt[2]);
}