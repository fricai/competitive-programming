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

const int N = 1 << 17, B = 32;
int a[N];

short solve() {
	int n; cin >> n; rep(i, 0, n) cin >> a[i];
	per(b, 0, B) {
		int x[2] = {0, 0};
		rep(i, 0, n) ++x[a[i] >> b & 1];
		if (~x[1] & 1) continue;
		return x[0] % 2 == 0 && x[1] % 4 == 3 ? -1 : +1;
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while (t--) {
		auto res = solve();
			if (res < 0) cout << "LOSE";
		else if (res > 0) cout << "WIN";
		else cout << "DRAW";
		cout << '\n';
	}
}