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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> p(n);
		for (auto &x : p) cin >> x;
		int g = 0, s = 0, b = 0, cur = 0, cur_b = 0;
		for (int i = 0, j = 0, k = 0; i < n; i = j) {
			while (j < n && p[i] == p[j]) ++j;
			cur += j - i;
			if (k == 0) {
				g = j - i;
				++k;
			} else if (k == 1) {
				s += j - i;
				if (g < s) ++k;
			} else {
				cur_b += j - i;
				if (2 * cur <= n && g < cur_b) b = cur_b;
			}
		}
		if (b == 0) cout << "0 0 0\n";
		else cout << g << ' ' << s << ' ' << b << '\n';
	}

}