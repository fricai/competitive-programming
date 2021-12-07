#include <bits/stdc++.h>

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

constexpr int N = 2e3 + 5, X = 3.6e6 + 5;
bitset<X> dp[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b; cin >> n >> a >> b;
	vector<int> d(n);
	for (auto &x : d)
		cin >> x;

	int p = a - b;
	int q = a + b;
	int sum = accumulate(all(d), 0);

	if (p > sum || p < -sum || ((p ^ sum) & 1) || q > sum || q < -sum || ((q ^ sum) & 1))
		return cout << "No\n", 0;
	p = (p + sum) / 2;
	q = (q + sum) / 2;

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
		dp[i + 1] = dp[i] | dp[i] << d[i];

	if (!dp[n][p] || !dp[n][q])
		return cout << "No\n", 0;

	string s(n, '0');
	char x[] = "RDUL";
	for (int i = n - 1; i >= 0; --i) {
		s[i] = x[dp[i][p] << 1 | dp[i][q]];
		if (!dp[i][p]) p -= d[i];
		if (!dp[i][q]) q -= d[i];
	}

	cout << "Yes\n" << s << '\n';
}
