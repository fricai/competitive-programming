#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

const int M = 1e9 + 7, N = 2e5 + 10;
int f[N], fi[N];

int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }
int mul(ll x, int y) { return x * y % M; }

int bpow(int a, ll b) {
	int res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1) res = mul(res, a);
	return res;
}

int C(int n, int r) {
	if (r < 0 || r > n || n < 0) return 0;
	return mul(f[n], mul(fi[r], fi[n - r]));
}

int solve() {
	int n; cin >> n;
	int l, r; cin >> l >> r;
	
	int ans = 0;

	int U = min(r - 1, n - l);
	int D = max(1, U - n + 1);
	
	set<int> s = {n / 2, (n + 1) / 2};
	for (auto L : s) {
		ans = add(ans, mul(D - 1, C(n, L)));
		for (int k = D; k <= U; ++k) {
			int neg = max(0, n - r + k);
			int pos = max(0, l + k - 1);
			ans = add(ans, C(n - pos - neg, L - neg));
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = 1;
	rep(i, 1, N) f[i] = mul(i, f[i - 1]);
	fi[N - 1] = bpow(f[N - 1], M - 2);
	per(i, 1, N) fi[i - 1] = mul(i, fi[i]);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}