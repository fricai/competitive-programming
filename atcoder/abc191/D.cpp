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

const ll B = 10000;
const ll inf = B * (2e5 + 30);

ll get(string s) {
	auto it = find(all(s), '.');
	ll res = stoi(string(begin(s), it));
	res *= B;
	if (it != end(s)) {
		++it;
		while (distance(it, end(s)) != 4) s.push_back('0');
		res += stoi(string(it, end(s)));
	}
	return res;
}

bool f(ll a, ll b) {
	return a * a <= b;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string _a, _b, _r; cin >> _a >> _b >> _r;

	auto a = get(_a);
	auto b = get(_b);
	auto r = get(_r);

	ll ans = 0;
	for (ll x = -inf; x <= inf; x += B) {
		ll d = r * r - (x - a) * (x - a);
		if (d < 0) continue;
		ll l = 0, r = sqrt(d) + 100;
		while (r - l > 1) {
			ll m = l + (r - l) / 2;
			(f(m, d) ? l : r)  = m;
		}
		assert(f(l, d) && !f(r, d));
		ll L = b - l;
		ll R = b + l;
		L += inf;
		R += inf;
		assert(L > 0 && R > 0);
		ans += R / B - (L - 1) / B;
	}

	cout << ans;
}