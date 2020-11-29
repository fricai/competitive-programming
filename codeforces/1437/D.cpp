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



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto &x : a) cin >> x;

		int dep = 0;
		vector<int> f(n + 1); f[0] = 1;
		for (int i = 1, j = 1; i < n; i = j) {
			++j; while (j < n && a[j - 1] < a[j]) ++j;
			if (!f[dep]) ++dep;
			--f[dep]; f[dep + 1] += j - i;
		}
		cout << dep + 1 << '\n';
	}	
}