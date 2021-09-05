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

int ways[20];

ll solve() {
	int n; cin >> n;

	int k = 0;
	for (int m = n; m != 0; m /= 10)
		++k;

	ll res = 0;
	rep(S, 0, 1 << max(0, k - 2)) {

		int T = S << 2;

		int m = n;
		ll prod = 1;
		rep(i, 0, k) {
			int r = 10 * (S >> i & 1) - (T >> i & 1) + (m % 10);
			if (r < 0)
				prod = 0;
			else
				prod *= ways[r];
			m /= 10;
		}
		res += prod;
	}
	return res - 2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 0, 10)
		rep(j, 0, 10)
			++ways[i + j];

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
