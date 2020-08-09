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

#pragma GCC optimize ("trapv")

const int N = 1 << 18, B = 44;
const ll mul = 1e9;
int g[B][B];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	ll ans = 0;
	rep(i, 0, n) {
		ll a = 0;
		string s; cin >> s;

		int j = -1;
		rep(i, 0, sz(s)) {
			if (s[i] == '.') { j = i; break; }
			a = 10 * a + (s[i] - '0');
		}
		if (j != -1) {
			rep(i, j + 1, sz(s)) a = 10 * a + (s[i] - '0');
			int x = sz(s) - j - 1;
			while (x < 9) a *= 10, ++x;
		} else a *= mul;
		// cout << a << '\n';
		ll b = a;
		int c2 = 0, c5 = 0;
		while (a % 2 == 0) a /= 2, ++c2;
		while (b % 5 == 0) b /= 5, ++c5;
		assert(c2 < B && c5 < B);
		rep(i, 0, B)
			rep(j, 0, B)
				if (c2 + i >= 18 && c5 + j >= 18)
					ans += g[i][j];
		++g[c2][c5];
	}
	cout << ans;
}