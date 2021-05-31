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

const int N = 1 << 18, M = 60, P = 15;
bool g[N][M];
int dp[1 << P];

int n, m, p;

pair<int, string> solve(int i) {
	vector<int> to_test;
	rep(j, 0, m) if (g[i][j]) to_test.push_back(j);

	int k = sz(to_test);

	rep(S, 0, 1 << k) dp[S] = 0;
	
	rep(i, 0, n) {
		int S = 0;
		rep(j, 0, k)
			if (g[i][to_test[j]])
				S |= 1 << j;
		++dp[S];
	}
	
	rep(S, 0, 1 << k)
		for (int T = S; --T &= S;)
			dp[T] += dp[S];
	
	int T = 0;
	rep(S, 0, 1 << k)
		if (n <= 2 * dp[S] && __builtin_popcount(T) < __builtin_popcount(S))
			T = S;
	
	string res(m, '0');
	rep(i, 0, k) if (T >> i & 1) res[to_test[i]] = '1';
	return {__builtin_popcount(T), res};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> p;
	rep(i, 0, n) {
		string s; cin >> s;
		rep(j, 0, m)
			g[i][j] = s[j] == '1';
	}
	
	string res(m, '0');
	int cur = 0;
	
	uniform_int_distribution<> dis(0, n - 1);
	for (int i = 0; i < 20; ++i) {
		auto [l, s] = solve(dis(rng));
		if (uax(cur, l)) res = s;
	}
	
	cout << res << '\n';
}