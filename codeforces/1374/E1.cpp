#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18;
int a[N], b[N], c[N];

ll solve() {
	int n, k; cin >> n >> k;

	int x = 0, y = 0, z = 0;
	rep(i, 0, n) {
		int t, u, v; cin >> t >> u >> v;
		if (u && !v) a[x++] = t;
		if (!u && v) b[y++] = t;
		if (u && v) c[z++] = t;
	}
	sort(a, a + x);
	sort(b, b + y);
	sort(c, c + z);
	int i = 0, j = 0, s = 0;

	ll ans = 0;
	while (k) {
		if (z <= s) {
			while (k && i < x && j < y)
				ans += a[i++] + b[j++], --k;
			if (k) return -1;
		} else if (x <= i || y <= j) {
			while (k && s < z) ans += c[s++], --k;
			if (k) return -1;
		} else {
			if (a[i] + b[j] > c[s]) ans += c[s++];
			else ans += a[i++] + b[j++]; 
			--k;
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << solve() << '\n';
}