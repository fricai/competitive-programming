#include <iostream>
using namespace std;

using ll = int64_t;
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

const ll M = (119 << 23) + 1;
const int N = 1 << 20;
ll f[N][2], inv[N];
ll nCr(int n, int r) {
	if (r > n || r < 0) return 0;
	return f[n][0] * f[r][1] % M * f[n - r][1] % M;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0][0] = f[0][1] = f[1][0] = f[1][1] = inv[1] = 1;
	rep(i, 2, N) {
		f[i][0] = i * f[i - 1][0] % M;
		inv[i] = (M - M / i * inv[M % i] % M) % M;
		f[i][1] = inv[i] * f[i - 1][1] % M;
	}

	int n, k; cin >> n >> k;
	ll ans = 0;
	rep(a, 1, n + 1) ans = (ans + nCr(n / a - 1, k - 1)) % M;
	cout << ans;
}