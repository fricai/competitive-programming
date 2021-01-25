#include <bits/stdc++.h>

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

const int N = 1 << 10;
bool g[N][N];

bool s[N], t[N];


bool solve() {
	int n; cin >> n;

	rep(i, 0, n) {
		rep(j, 0, n) {
			char c; cin >> c;
			g[i][j] = (c == '1');
		}
	}

	rep(i, 0, n) {
		rep(j, 0, n) {
			char c; cin >> c;
			g[i][j] ^= (c == '1');
		}
	}

	rep(b, 0, 2) {
		fill(s, s + n, 0);
		fill(t, t + n, 0);
		
		rep(i, 0, n) s[i] = b ^ g[i][0];
		rep(i, 0, n) t[i] = s[i] ^ g[i][i];

		bool works = true;
		rep(i, 0, n) rep(j, 0, n) if (g[i][j] != (s[i] ^ t[j])) works = false;
		if (works) return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}