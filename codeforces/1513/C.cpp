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
int a[N];

int add(int x, int y) {
	x += y;
	if (M <= x) x -= M;
	return x;
}

int solve() {
	ll k; int m;
	cin >> k >> m;
	ll ans = 0;
	while (k != 0) {
		ans = add(ans, a[k % 10 + m]);
		k /= 10;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill_n(a, 10, 1);
	rep(i, 10, N) a[i] = add(a[i - 9], a[i - 10]);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}