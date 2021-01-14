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

	string s; cin >> s;

	int n = sz(s);

	ll ans = 0;
	rep(S, 0, 1 << (n - 1))  {
		ll sum = 0, cur = 0;
		rep(i, 0, n) {
			cur = 10 * cur + (s[i] - '0');
			if (S >> i & 1) {
				sum += cur;
				cur = 0;
			}
		}
		sum += cur;
		ans += sum;
	}
	cout << ans;
}