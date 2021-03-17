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

void solve() {
	int n, k; cin >> n >> k;
	n -= k - 3;
	rep(i, 3, k) cout << "1 ";
	if (n & 1) cout << (n - 1) / 2 << ' ' << (n - 1) / 2 << ' ' << 1 << '\n';
	else if (n % 4) cout << (n - 2) / 2 << ' ' << (n - 2) / 2 << ' ' << 2 << '\n';
	else cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}