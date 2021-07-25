#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
	int n; cin >> n;
	vector<array<int, 5>> a(n);
	for (auto &x : a)
		for (auto &y : x)
			cin >> y;
	auto better = [&](int i, int j) {
		int count = 0;
		rep(k, 0, 5)
			count += a[i][k] < a[j][k];
		return count >= 3;
	};
	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int i, int j) {
		bool a = better(i, j), b = better(j, i);
		if (a == b)
			return i < j;
		return !a;
	});
	int ans = ord.back();
	rep(i, 0, n)
		if (i != ans && !better(ans, i))
			return -1;
	return ans + 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}