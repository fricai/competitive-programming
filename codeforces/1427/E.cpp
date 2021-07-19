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

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<tuple<ll, char, ll>> op;
	set<ll> reached;
	auto do_sum = [&](ll x, ll y) {
		assert(reached.count(x) && reached.count(y));
		reached.insert(x + y);
		op.emplace_back(x, '+', y);
	};
	auto do_xor = [&](ll x, ll y) {
		assert(reached.count(x) && reached.count(y));
		reached.insert(x ^ y);
		op.emplace_back(x, '^', y);
	};
	
	auto get_multiple = [&](ll q, ll x) {
		for (ll res = 0; q; q >>= 1) {
			if (q & 1) {
				if (res)
					do_sum(res, x);
				res += x;
			}
			do_sum(x, x);
			x += x;
		}
	};
	
	ll x; cin >> x;
	reached.insert(x);

	ll p = 1;
	while (p < x) p <<= 1;
	p >>= 1;
	
	get_multiple(p, x);
	do_xor(p * x, x);

	ll y = (p * x) ^ x;
	ll a, b;
	euclid(x, y, a, b);
	b = -b;
	if (a < 0) {
		ll r = (-a + y - 1) / y;
		a += r * y;
		b += r * x;
	}
	assert(a >= 0);
	assert(b >= 0);
	assert(a * x - b * y == 1);
	
	if (b & 1) {
		a += y;
		b += x;
	}
	get_multiple(a, x);
	get_multiple(b, y);
	if (a && b)
		do_xor(a * x, b * y);
	
	assert(reached.count(1));
	cout << sz(op) << '\n';
	for (auto [x, c, y] : op)
		cout << x << ' ' << c << ' ' << y << '\n';
}