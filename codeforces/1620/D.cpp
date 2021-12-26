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

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	int ans = 1e9;
	for (int one : {0, 1}) {
		for (int two : {0, 1, 2}) {
			if ([&]() -> bool {
					bool x[3] = {};

					x[0] = true;
					x[1] = one > 0 || two > 1;
					x[2] = two;

					for (auto y : a)
						if ((y == 1 && !one) || !x[y % 3])
							return true;
					return false;
				}())
				continue;

			int cur = 0;
			for (auto y : a) {
				if (y % 3 == 0) uax(cur, y / 3 - (one && two));
				if (y % 3 == 1) uax(cur, y / 3 - (y > 1 && two > 1));
				if (y % 3 == 2) uax(cur, y / 3);
			}

			uin(ans, cur + one + two);
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
