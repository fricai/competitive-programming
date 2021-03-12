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

const int N = 3e5 + 10;
vector<int> p[2];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	int n = sz(s);
	ll ans = n; ans *= n + 1; ans /= 2;
	for (int l = 0; l < n; ++l) {
		bool ok = false;
		for (int r = l; r < n; ++r) {
			for (int k = 1; r - 2 * k >= l; ++k) {
				if (s[r] == s[r - k] && s[r - k] == s[r - 2 * k]) {
					ok = true;
					break;
				}
			}
			if (ok) break;
			--ans;
		}
	}

	cout << ans;
}