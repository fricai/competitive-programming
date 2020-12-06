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

const int N = 1 << 7;
int x[N], y[N];

bool solve() {
	
	int n, k; cin >> n >> k;
	rep(i, 0, n) cin >> x[i] >> y[i];
	rep(i, 0, n) {
		bool yes = true;
		rep(j, 0, n) if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) yes = false;
		if (yes) return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? 1 : -1) << '\n';
}