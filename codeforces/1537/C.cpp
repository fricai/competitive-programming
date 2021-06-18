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

const int inf = 2e9;

void solve() {
	int n; cin >> n;
	vector<int> h(n);
	for (auto &x : h) cin >> x;
	sort(all(h));

	if (sz(h) > 2) {
		int mn = inf;
		rep(i, 1, n) uin(mn, h[i] - h[i - 1]);

		vector<int> opt;
		rep(i, 1, n)
			if (h[i] - h[i - 1] == mn)
				opt.push_back(i);
		int i = opt[0];

		rotate(begin(h), begin(h) + i, end(h));
	}
	
	for (auto x : h) cout << x << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}