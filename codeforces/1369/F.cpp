#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int T = 1 << 17;
int a[T], b[T];

bool win(ll s, ll e) {
	if (e & 1) return ~s & 1;
	if (e / 2 < s) return s & 1;
	if (e / 4 < s) return 1;
	return win(s, e / 4);
}

bool lose(ll s, ll e) {
	if (e / 2 < s) return 1;
	return win(s, e / 2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	rep(i, 0, t) {
		ll s, e; cin >> s >> e;
		a[i] = win(s, e);
		b[i] = lose(s, e);
	}
	bool l = 1, w = 0;
	rep(i, 0, t) {
		if (l && w) break;
		if (!l && !w) break;
		if (w) w = a[i] ^ 1, l = b[i] ^ 1;
		else w = a[i], l = b[i];
	}
	cout << w << ' ' << l;
}