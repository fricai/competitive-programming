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

const int X = 1e7 + 10;
bool sieve[X];
int ker[X];
bool exists[X];

int solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n, 1);
	for (auto &x : a) cin >> x, x = ker[x];

	// for (auto x : a) {
	// 	cerr << x << ' ';
	// }
	// cerr << '\n';

	int ans = 0;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && !exists[a[j]]) exists[a[j++]] = 1;
		rep(k, i, j) exists[a[k]] = 0;
		++ans;
	}
	
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill_n(ker, X, 1);
	rep(i, 2, X) {
		if (sieve[i]) continue;
		for (int j = i; j < X; j += i) {
			sieve[j] = 1;
			int r = j;
			bool parity = 0;
			while (r % i == 0) r /= i, parity ^= 1;
			if (parity) ker[j] *= i;
		}
	}

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}