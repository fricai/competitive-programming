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

const int X = 64;
ll c[X][X];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b; cin >> a >> b;

	c[0][0] = 1;
	rep(i, 1, X) {
		c[i][0] = 1;
		rep(j, 0, i) c[i][j + 1] = c[i - 1][j + 1] + c[i - 1][j];
	}

	ll k; cin >> k; --k;
	string s(a + b, 'b');
	for (int i = 0; i < sz(s); ++i) {
		if (k < c[a + b - 1][b]) {
			s[i] = 'a';
			--a;
		} else {
			k -= c[a + b - 1][b];
			s[i] = 'b';
			--b;
		}
	}
	
	assert(a == 0 && b == 0);

	cout << s << '\n';	
}