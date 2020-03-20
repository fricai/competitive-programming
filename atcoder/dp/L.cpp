#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define ff first
#define ss second

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using pll = pair<ll, ll>;

const int N = 3001;
int a[N];
pll dp[N][N];

pll f(int l, int r) {
	if (l > r) return {0, 0};
	auto &x = dp[l][r];
	if (x == pll(-1, -1)) {
		auto tl = f(l + 1, r); swap(tl.ff, tl.ss);
		auto tr = f(l, r - 1); swap(tr.ff, tr.ss);
		tl.ff += a[l]; tr.ff += a[r];
		x = (tl.ff - tl.ss > tr.ff - tr.ss ? tl : tr);
	}
	return x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) rep(j, 0, n) dp[i][j] = {-1, -1};
	auto tmp = f(0, n - 1);
	cout << tmp.ff - tmp.ss;
}