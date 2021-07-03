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

// #pragma GCC optimize ("trapv")

const int M = 1e9 + 7;

vector<ll> opt = {2, 4, 8, 16, 32, 3, 9, 27, 5, 25, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

ll cnt(ll n, ll a, ll b) {
	// find numbers <= n of the form ax + b
	// ax + b <= n
	// ax <= (n - b)
	// x <= (n - b) / a
	// 0 <= x <= floor((n - b) / a)
	return b > n ? 0 : (n - b) / a + 1;
}

int solve(ll n) {
	// ll n; cin >> n;
	
	ll cur = 1;

	ll ans = 0;
	vector<ll> mods = {0};
	for (auto d : opt) {
		ll nxt = lcm(cur, d);
		
		vector<ll> new_mods;
		for (auto x : mods)
			for (ll z = 0; z + x < nxt; z += cur)
				new_mods.push_back(z + x);
		
		mods.clear();
		for (auto x : new_mods)
			if (x % d)
				ans = (ans + (cnt(n, nxt, x) % M) * d) % M;
			else
				mods.push_back(x);
		cur = nxt;

		// for (auto x : new_mods) cerr << x << ' ';
		// cerr << '\n';
	}
	return ans;
}

ll f(int x) {
	for (int k = 1; ; ++k)
		if (x % k) return k;
	assert(0);
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	sort(all(opt));

	// ll sum = 0;
	// for (int i = 1; ; ++i) {
	// 	sum += f(i);
	// 	cerr << i << "\n";
	// 	if (sum != solve(i)) {
	// 		break;
	// 	}
	// }
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		cout << solve(n) << '\n';
	}
}