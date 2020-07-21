#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 17;
int a[N], dp[N], n;

bool f(int i) {
	if (i == n) return false;
	if (dp[i] < 0) {
		if (a[i]) dp[i] = true;
		else dp[i] = !f(i + 1);
	}
	return dp[i];
}

bool solve() {
	cin >> n;
	rep(i, 0, n) {
		cin >> a[i];
		a[i] = (a[i] > 1);
		dp[i] = -1;
	}
	return f(0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "First" : "Second") << '\n';
}