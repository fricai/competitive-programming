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

int solve() {
	int n; cin >> n;
	vector<int> a(n), f(n), g(n);
	for (auto &x : a) cin >> x, ++g[--x];
	if (*max_element(all(g)) > (n + 1) / 2) return -1;

	auto add = [&](int x) { ++f[a[x]]; };

	int cnt = 0;
	add(0); add(n - 1);
	rep(i, 1, n) if (a[i - 1] == a[i]) ++cnt, add(i - 1), add(i);
	return cnt + max(0, *max_element(all(f)) - cnt - 2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';	
}