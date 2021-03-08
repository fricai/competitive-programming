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

	int n; string _s, _t, s, t; cin >> n >> _s >> _t;
	rep(i, 0, n) if (_s[i] != _t[i]) s += _s[i], t += _t[i];
	sort(all(_s)); sort(all(_t));
	if (_s != _t) return cout << "-1\n", 0;
	n = sz(s);
	int o = 0, z = 0;
	rep(i, 0, n) {
		if (s[i] == '0') ++z, o = max(0, o - 1);
		else ++o, z = max(0, z - 1);
	}
	cout << o + z << '\n';
}