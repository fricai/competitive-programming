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

	ll n; cin >> n;
	if (n <= 20) {
		set<int> s;
		for (int a = 0; a <= n; ++a) {
			for (int b = 0; a + b <= n; ++b) {
				for (int c = 0; a + b + c <= n; ++c) {
					int d = n - a - b - c;
					s.insert(50 * a + 10 * b + 5 * c + d);
				}
			}
		}
		cout << sz(s) << '\n';
	} else cout << 49 * n - 247 << '\n';
}