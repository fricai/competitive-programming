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

ll solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x, x &= 1;
	int cnt[2] = {};
	for (auto x : a)
		++cnt[x];

	if (abs(cnt[0] - cnt[1]) > 1)
		return -1;

	ll ans = 1ll * n * (n - 1) / 2;
	for (auto b : {0, 1}) {
		if (cnt[b] != (n + 1) / 2)
			continue;
		ll cur = 0;
		queue<int> d[2];
		rep(i, 0, n) d[a[i]].push(i);
		rep(i, 0, n) {
			int u = d[(i ^ b) & 1].front();
			d[(i ^ b) & 1].pop();
			cur += abs(u - i);
		}
		uin(ans, cur / 2);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
