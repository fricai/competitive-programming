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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> a(n), b(n);
	rep(i, 0, n) cin >> a[i] >> b[i];

	vector<int> ans(n + 1);
	map<int, int> mp;
	rep(i, 0, n) {
		++mp[a[i]];
		--mp[a[i] + b[i]];
	}

	int p = 0, cur = 0;
	for (auto [x, del] : mp) {
		ans[cur] += x - p;
		cur += del;
		p = x;
	}
	assert(cur == 0);

	for (int k = 1; k <= n; ++k) 
		cout << ans[k] << ' ';
	cout << '\n';
}
