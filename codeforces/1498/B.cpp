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

const int B = 31;

int solve() {
	int n, w;
	cin >> n >> w;

	// sz <= w < 2 * s

	vector<int> f(B);
	rep(i, 0, n) {
		int x; cin >> x;
		++f[31 - __builtin_clz(x)];
	}

	int cnt = 0;
	while (true) {
		int x = w;
		per(i, 0, B) {
			while (f[i] && ((1ll << i) <= x)) {
				x -= 1ll << i;
				--f[i];
			}
		}
		
		++cnt;
		if (x == w) break;
	}
	return cnt - 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}