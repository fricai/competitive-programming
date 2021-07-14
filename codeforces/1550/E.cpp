#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector cnt(n + 1, vector(k, 0));

	per(i, 0, n)
		rep(j, 0, k)
			if (s[i] == 'a' + j || s[i] == '?')
				cnt[i][j] = cnt[i + 1][j] + 1;
			
	auto ok = [&](int x) {
		vector nxt(n + 1, vector(k, n + 1));
		per(i, 0, n)
			rep(j, 0, k)
				if (cnt[i][j] < x)
					nxt[i][j] = nxt[i + 1][j];
				else
					nxt[i][j] = i + x;
		
		vector dp(1 << k, n + 1);
		dp[0] = 0;
		
		rep(S, 0, 1 << k)
			if (dp[S] < n)
				rep(i, 0, k)
					if (~S >> i & 1)
						uin(dp[S | 1 << i], nxt[dp[S]][i]);
		
		return dp.back() <= n;
	};
	
	int l = 0, r = n / k + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		(ok(m) ? l : r) = m;
	}
	cout << l << '\n';
}