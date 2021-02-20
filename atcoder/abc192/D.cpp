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

const ll inf = 1.5e18;
string s;
ll x;

bool f(ll b) {
	ll res = 0;
	for (auto c : s) {
		ll add = c - '0';
		if (x < add) return false;
		if (res > (x - add) / b) return false;
		res = b * res + add;
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> x;
	int d = *max_element(all(s)) - '0';

	assert(s[0] != '0');

	if (sz(s) == 1) return cout << (s.back() - '0' <= x), 0;
	
	assert(!f(inf));

	if (f(d + 1)) {
		ll l = d + 1, r = inf;
		while (r - l > 1) {
			ll m = l + (r - l) / 2;
			(f(m) ? l : r) = m;
		}
		cout << l - d;
	} else cout << 0;
}