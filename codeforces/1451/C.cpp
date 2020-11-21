#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18, A = 26;
int fa[A + 1], fb[A + 1];

bool solve() {
	int n, k; cin >> n >> k;
	fill(fa, fa + A, 0); fill(fb, fb + A, 0);
	rep(i, 0, n) {
		char c; cin >> c;
		++fa[c - 'a'];
	}
	rep(i, 0, n) {
		char c; cin >> c;
		++fb[c - 'a'];
	}
	rep(c, 0, A) {
		if (fa[c] < fb[c] || (fa[c] - fb[c]) % k != 0) return 0;
		fa[c + 1] += fa[c] - fb[c];
		fa[c] = fb[c];
	}
	return 1;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) cout << (solve() ? "Yes" : "No") << '\n';
}