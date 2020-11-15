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

const int N = 1 << 18;
ll w[N];
int ord[N];

vector<int> solve() {
	int n; ll W; cin >> n >> W;
	ll s = 0;

	vector<int> v;
	rep(i, 0, n) cin >> w[i];
	iota(ord, ord + n, 0);
	sort(ord, ord + n, [&](int x, int y) {
		return w[x] > w[y];
	});
	rep(i, 0, n) {
		s += w[ord[i]];
		if (s <= W) v.push_back(ord[i]);
		else s -= w[ord[i]];
	}
	if ((W + 1) / 2 <= s && s <= W) return v;
	return { };
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		auto v = solve();
		if (v.empty()) cout << -1 << '\n';
		else {
			cout << sz(v) << '\n';
			for (auto x : v) cout << x + 1 << ' ';
			cout << '\n';
		}
	}
}