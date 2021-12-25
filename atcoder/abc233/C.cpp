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

	int n; ll x; cin >> n >> x;
	vector<vector<int>> a(n);
	for (auto &v : a) {
		int x; cin >> x;
		v.resize(x);
		for (auto &y : v) cin >> y;
	}

	int ans = 0;
	auto rec = [&](const auto &self, int i, ll prod) -> void {
		if (i == n) {
			return void(ans += prod == x);
		}
		for (auto y : a[i]) {
			if (y <= x / prod) {
				self(self, i + 1, prod * y);
			}
		}
	};
	rec(rec, 0, 1);
	cout << ans << '\n';
}
