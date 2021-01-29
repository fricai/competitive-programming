#include <bits/stdc++.h>
#include <atcoder/modint>

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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17;
using mint = atcoder::static_modint<3>;
mint f[N], g[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t; cin >> s >> t;
	rep(i, 0, sz(s)) f[i + 1] = f[i] + (s[i] == 'A' ? 1 : 2);
	rep(i, 0, sz(t)) g[i + 1] = g[i] + (t[i] == 'A' ? 1 : 2);
	int q; cin >> q;
	while (q--) {
		int a, b, c, d; cin >> a >> b >> c >> d; --a; --c;
		cout << (g[d] - g[c] != f[b] - f[a] ? "NO" : "YES") << '\n';
	}
}