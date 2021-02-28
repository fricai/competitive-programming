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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int o = 0;
	for (auto x : a) if (x == 1) ++o;
	
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int i; cin >> i; --i;
			if (a[i] == 0) ++o;
			else --o;
			
			a[i] = 1 - a[i];
			
		} else {
			int k; cin >> k;
			
			cout << (k <= o ? 1 : 0) << '\n';
		}
	}
}