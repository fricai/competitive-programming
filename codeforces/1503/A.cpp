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

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int a = 0, b = 0;

	int ones = 0;
	for (auto c : s) ones += c == '1';
	if (ones & 1) return void(cout << "NO\n");

	string p, q;
	int cur = 0;
	rep(i, 0, n) {
		if (s[i] == '1') {
			if (cur + cur < ones) p += '(', q += '(', ++a, ++b;
			else p += ')', q += ')', --a, --b;
			++cur;
		} else {
			if (a > b) p += ')', q += '(', --a, ++b;
			else p += '(', q += ')', ++a, --b;
		}
		if (a < 0 || b < 0) return void(cout << "NO\n");
	}
	if (a || b) return void(cout << "NO\n");
	cout << "YES\n" << p << '\n' << q << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}