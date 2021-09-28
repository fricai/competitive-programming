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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	priority_queue<pair<int, int>> pq;
	rep(i, 0, n)
		if (a[i])
			pq.push({a[i], i});

	vector<pair<int, int>> ans;
	while (sz(pq) > 1) {
		auto [x, i] = pq.top(); pq.pop();
		auto [y, j] = pq.top(); pq.pop();
		--x; --y;
		ans.emplace_back(i, j);
		if (x) pq.push({x, i});
		if (y) pq.push({y, j});
	}

	cout << sz(ans) << '\n';
	for (auto [i, j] : ans)
		cout << i + 1 << ' ' << j + 1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
