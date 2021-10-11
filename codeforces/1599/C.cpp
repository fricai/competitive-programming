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

ll C(int n, int k) {
	ll res = 1;
	rep(i, 0, k)
		res *= n - i, res /= i + 1;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; double p; cin >> n >> p;
	for (int k = 0; k <= n; ++k) {
		ll tot = C(k, 3) + C(k, 2) * C(n - k, 1);
		tot *= 2;
		tot += C(k, 1) * C(n - k, 2);
		if (tot >= 2 * C(n, 3) * p)
			return cout << k << '\n', 0;
	}
}
