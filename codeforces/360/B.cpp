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

#define int ll

const int N = 1 << 11;
int dp[N], a[N], n;

int f(ll x) {
	for (int i = 0; i <= n; ++i) {
		dp[i] = i;
		for (int j = 0; j < i; ++j)
			if (i == n || abs(a[i] - a[j]) <= (i - j) * x)
				ckmin(dp[i], dp[j] + i - j - 1);
	}
	return dp[n];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k; cin >> n >> k;
	rep(i, 0, n) cin >> a[i];
	int l = -1, r = 2e9 + 10;
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		(f(m) <= k ? r : l) = m;
	}
	cout << r;
}