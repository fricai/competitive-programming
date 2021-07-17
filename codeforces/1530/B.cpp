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

void solve() {
	int h, w; cin >> h >> w;

	vector t(h, vector(w, 0));

	auto taken = [&](int i, int j) {
		return 0 <= i && i < h && 0 <= j && j < w && t[i][j];	
	};
	auto check = [&](int i, int j) {
		for (auto a : {-1, 0, +1})
			for (auto b : {-1, 0, +1})
				if ((a || b) && taken(i + a, b + j))
					return 0;
		return 1;
	};

	t[0][0] = 1;

	for (int j = 0; j < w; ++j)
		t[0][j] = check(0, j);
	for (int i = 0; i < h; ++i)
		t[i][0] = check(i, 0);
	for (int j = 0; j < w; ++j)
		t[h - 1][j] = check(h - 1, j);
	for (int i = 0; i < h; ++i)
		t[i][w - 1] = check(i, w - 1);
	
	for (auto v : t) {
		for (auto x : v)
			cout << x;
		cout << '\n';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}