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
	// cerr << n << ' ' << r << '\n';
	if (r < 0 || r > n || n < 0) return 0;
	return mul(f[n], mul(fi[r], fi[n - r]));
}

int solve() {
	int n; cin >> n;
	
	int l, r; cin >> l >> r;
	int ans = 0;
	set<int> s = {n / 2, (n + 1) / 2};

	int U = min(r - 1, n - l);
	int D = max(1, min(1 - l, r - n));

	for (auto L : s) {
		// [D, U] we explicity find
		// for [1, D), ans is C(n, L)
		ans = add(ans, mul(D - 1, C(n, L)));
		for (int k = D; k <= U; ++k) {
			/*
				we require a[i] = i - k for L

				if i + k > r, we must have a[i] = i - k
					=> i > r - k and i > 0
					=> max(0, r - k) < i <= n


					l <= i - k
					=> l + k <= i however max(0, r - k) + 1 <= i		
			*/
			
			int neg = max(0, n - r + k);
			/*
				n <= n - r + k
				=> 0 <= -r + k
				=> r <= k <= K
				
				for k in [r, K], neg = n
				so k < r
			*/
			
			/*
				if neg = 0,
					=> 0 >= n - r + k
					=> k <= r - n
			*/

			/*
				if i - k < l, we must have a[i] = i + k
					=> i < l + k and i < n + 1
					=> i < min(l + k, n + 1)
					=> 1 <= i < min(l + k, n + 1)
				
				the condition i + k <= r must be satisfied
					=> i <= r - k however i <= n
					so if r - k < n we have issue

					i < max(l + k, n + 1)
					i < r - k + 1
					so if r - k + 1 < max(l + k, n + 1),
						we have issues
			*/

			int pos = max(0, l + k - 1);
			/*
				if pos = 0,
					0 >= l + k - 1
					=> 1 - l >= k
					=> k <= 1 - l
			*/

			/*
				for k <= 1 - l,
					pos = 0
				for k <= r - n,
					neg = 0

				so for 1 <= k <= min(1 - l, r - n),
					pos = neg = 0
				
				for (min(1 - l, r - n), min(r - 1, n - l)]
					min(1 - l, r - n) = min(1 + n - n - l, r - 1 + 1 - n)
						= min(n - l, r - 1) - (n - 1)
			*/
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