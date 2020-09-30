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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

vector<pair<int, int>> ans;

void add(int x, int y) { ans.eb(x + 1, y + 1); }

void f(int l, int r) {
	if (r - l == 1) return;
	int m = (l + r) / 2;
	f(l, m); f(m, r);
	for (int i = l, j = m; j < r; ++i, ++j) add(i, j);
}

const int B = 20;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	int sz = 1;
	while (sz <= n) sz <<= 1;
	sz >>= 1;
	f(0, sz);
	f(n - sz, n);
	
	cout << sz(ans) << '\n';
	for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}