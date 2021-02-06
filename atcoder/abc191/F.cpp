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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> to_test;
	for (auto x : a) {
		for (int d = 1; d * d <= x; ++d) {
			if (x % d) continue;
			to_test.push_back(d);
			if (d * d != x) to_test.push_back(x / d);
		}
	}

	int mn = *min_element(all(a));
	sort(all(to_test)); to_test.erase(unique(all(to_test)), end(to_test));
	
	int ans = 0;
	for (auto d : to_test) {
		if (d > mn) break;
		int g = 0;
		for (auto x : a)
			if (x % d == 0) g = gcd(g, x);
		ans += g == d;
	}

	cout << ans;
}