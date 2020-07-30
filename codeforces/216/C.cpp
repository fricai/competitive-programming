#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >> n >> m >> k;
	vector<int> res;
	rep(i, 0, k) res.eb(0);
	for (int d = n - 1; d < n + m; ) {
		res.eb(d);
		if (k > 1) {
			++d;
			if (d == n + m) break;
			rep(i, 1, k) res.eb(d);
			d += n - 1;
		} else d += n - 1;
	}

	cout << sz(res) << '\n';
	trav(x, res) cout << x + 1 << ' ';
}