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

void solve() {
	int n, x; cin >> n >> x;

	ll s = 0;
	vector<int> w(n);
	for (auto &u : w) cin >> u, s += u;
	if (s == x) return void(cout << "NO\n");
	sort(all(w));
	ll cur = 0;
	rep(i, 0, n - 1) {
		cur += w[i];
		if (cur == x) {
			swap(w[i], w[i + 1]);
		}
	}

	cout << "YES\n";
	for (auto u : w) cout << u << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}