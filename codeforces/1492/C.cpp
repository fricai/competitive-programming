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

const int N = 1 << 18;
int f[N], g[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m; string s, t; cin >> n >> m >> s >> t;

	vector<int> f(m), g(m);
	for (int i = 0, j = 0; j < m; ++i) {
		if (s[i] != t[j]) continue;
		f[j++] = i;
	}

	for (int i = n - 1, j = m; j > 0; --i) {
		if (s[i] != t[j - 1]) continue;
		g[--j] = i;
	}

	// for (auto x : f) cerr << x << ' ';
	// cerr << '\n';
	
	// for (auto x : g) cerr << x << ' ';
	// cerr << '\n';

	int ans = 0;
	rep(i, 1, m) ckmax(ans, g[i] - f[i - 1]);
	cout << ans;
}