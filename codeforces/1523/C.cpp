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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<int> v;
	
	rep(i, 0, n) {
		if (v.empty()) {
			assert(i == 0 && a[i] == 1);
		} else if (v.back() + 1 != a[i]) {
			if (a[i] != 1) {
				while (!v.empty() && v.back() + 1 != a[i])
					v.pop_back();
				assert(!v.empty() && v.back() + 1 == a[i]);
				v.pop_back();
			}
		} else
			v.pop_back();
		
		for (auto x : v)
			cout << x << ".";
		cout << a[i] << '\n';
		
		v.push_back(a[i]);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}