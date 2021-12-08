#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int X = 3000 + 5;
using mint = atcoder::modint998244353;
const mint zero = 0;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	vector dp(n + 1, vector<mint>(X));

	// dp[i + 1][x] = number of sequences of length i + 1 which end with x and we have 
	// 			a[i] <= x <= b[i]
	
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		mint cur = zero;
		for (int x = 0; x < a[i]; ++x)
			cur += dp[i][x];
		for (int x = a[i]; x <= b[i]; ++x) {
			cur += dp[i][x];
			dp[i + 1][x] = cur;
		}
	}

	cout << accumulate(all(dp[n]), zero).val() << '\n';
}
