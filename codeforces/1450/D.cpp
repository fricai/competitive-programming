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

const int N = 3e5 + 20;
int a[N];
bool ok[N];
int f[N];

void solve() {
	int n; cin >> n;
	fill_n(f, n, 0);
	fill_n(ok, n, 0);
	rep(i, 0, n) cin >> a[i], ++f[--a[i]];
	
	ok[1] = 1; rep(x, 0, n) ok[1] &= f[x] == 1;
	ok[n] = f[0];
	if (ok[n]) {
		for (int l = 0, r = n - 1, i = n, x = 0; i > 1; --i, ++x) {
			ok[i] = 1;
			if (--f[x] == 0 && f[x + 1]) {
				if (a[l] == x) ++l;
				else if (a[r] == x) --r;
				else break;
			} else break;
		}
	}

	for (int i = 1; i <= n; ++i) cout << ok[i];
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();	
}