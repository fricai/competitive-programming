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

const int N = 1 << 17;
int cnt[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	ll s = 0;
	rep(i, 0, n) {
		int x; cin >> x; s += x;
		++cnt[x];
	}
	int q; cin >> q;
	while (q--) {
		int b, c; cin >> b >> c;
		s += cnt[b] * (c - b);
		cnt[c] += cnt[b];
		cnt[b] = 0;
		cout << s << '\n';
	}
}