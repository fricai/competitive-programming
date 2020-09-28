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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int M = 1e9 + 7;
const ll inv3 = 333333336;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; string s; cin >> n >> s;
	int a = 0, c = 0, x = 0, y = 0;
	ll pb = inv3, pf = inv3;
	for (auto t : s) if (t == 'c') ++c; else if (t == '?') ++y, pb = 3 * pb % M;
	ll ans = 0;
	for (auto t : s) {
		if (t == 'c') --c;
		if (t == '?') --y, pb = pb * inv3 % M;
		if (t == 'b' || t == '?') {
			ans += pf * (3 * a + x) % M * pb % M * (3 * c + y) % M;
			ans %= M;
		}
		if (t == 'a') ++a;
		if (t == '?') ++x, pf = 3 * pf % M;	
	}
	cout << ans;
}