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

const int N = 1 << 18, inf = 1e9;
int a[N], n, k;

bool f(int x) {
	for (auto parity : {0, 1}) {
		int m = 0;
		rep(i, 0, n) {
			if (parity) ++m, parity ^= 1;
			else if (a[i] <= x) parity ^= 1, ++m;
		}
		if (k <= m) return 1;
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	rep(i, 0, n) cin >> a[i];
	int l = 0, r = inf;
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		(f(m) ? r : l) = m;
	}
	cout << r << '\n';
}