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

	int n, t; cin >> n >> t;

	int mi = 1e9, ans = -1;
	rep(i, 0, n) {
		int s, d; cin >> s >> d;
		int cur = s;
		while (cur < t) cur += d;
		if (ckmin(mi, cur)) ans = i;
	}
	cout << ans + 1;
}