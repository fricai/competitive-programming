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

int solve() {
	string a, b; cin >> a >> b;

	int tot = sz(a) + sz(b);
	int mn = tot;
	for (int l_a = 0; l_a < sz(a); ++l_a) {
		string s = "";
		for (int r_a = l_a + 1; r_a <= sz(a); ++r_a) {
			s += a[r_a - 1];
			for (int l_b = 0; l_b < sz(b); ++l_b) {
				string t = "";
				for (int r_b = l_b + 1; r_b <= sz(b); ++r_b) {
					t += b[r_b - 1];
					if (s == t) ckmin(mn, tot - sz(s) - sz(t));
				}
			}
		}
	}
	return mn;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}