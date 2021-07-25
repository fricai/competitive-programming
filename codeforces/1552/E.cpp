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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector c(n * k, 0);
	for (auto &x : c)
		cin >> x, --x;
	
	vector<vector<int>> pos(n);
	rep(i, 0, n * k) pos[c[i]].push_back(i);
	
	vector<int> cnt(n * k, (n + k - 2) / (k - 1));
	
	vector<pair<int, int>> ans(n);
	auto place = [&](int x, int y) -> bool {
		rep(i, x, y + 1)
			if (cnt[i] == 0)
				return false;
		rep(i, x, y + 1)
			--cnt[i];
		ans[c[x]] = {x, y};
		return true;
	};

	vector<bool> vis(n);
	vector<tuple<int, int, int>> opt; 
	rep(i, 0, n)
		rep(j, 1, k)
			opt.emplace_back(pos[i][j - 1], pos[i][j], i);
	
	sort(all(opt), [&](auto x, auto y) {
		return get<1>(x) < get<1>(y);
	});

	for (auto [i, j, c] : opt) {
		if (vis[c]) continue;
		vis[c] = place(i, j);
	}
	
	assert(sz(ans) == n);
	for (auto [x, y] : ans)
		cout << x + 1 << ' ' << y + 1 << '\n';
}