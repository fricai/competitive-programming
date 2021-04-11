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

const int M = 1e9 + 7, N = 1 << 18;

ll f[N];

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	int t = ~0;
	for (auto &x : a) cin >> x, t &= x;

	for (auto x : a) if ((t & x) != t) return 0;

	vector<int> p;
	rep(i, 0, n) if (a[i] == t) p.push_back(i);
	ll ans = sz(p);
	ans = ans * (ans - 1);
	ans %= M;
	ans *= f[n - 2];
	return ans % M;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = 1;
	rep(i, 1, N) f[i] = f[i - 1] * i % M;

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}