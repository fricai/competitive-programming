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

const int U = 1001;
const ll MX = 1e18;
vector<int> primes;
ll square_free[U];
vector<int> groups[U];

bool is_prime(int n) {
	for (int d = 2; d * d <= n; ++d)
		if (n % d == 0)
			return 0;
	return 1;
}

int calls = 0;
ll ask(ll g) {
	assert(g <= MX);
	++calls;
	cout << "? " << g << endl;
	ll q; cin >> q;
	return q;
}

const int max_calls = 22;

void solve() {
	ll ans = 1; calls = 0;
	for (int grp = 0; calls < max_calls; ++grp) {
		ll g = ask(square_free[grp]);
		
		vector<int> look;
		for (auto p : groups[grp]) if (g % p == 0) look.push_back(p);
		
		int i = 0;
		while (calls < max_calls && i < sz(look)) {
			ll power = look[i];
			while (power <= MX / look[i]) power *= look[i];
			int cnt = 0;
			for (ll g = ask(power); g != 1; ++cnt) g /= look[i];
			ans *= cnt + 1;
			++i;
		}
		while (i < sz(look)) ans <<= 1, ++i;
	}
	cout << "! " << ans + max(ans, 7ll) << endl;
}

signed main() {
	for (int p = 2; p <= U; ++p) if (is_prime(p)) primes.push_back(p);

	for (int i = 0, j = 0, cnt = 0; i < sz(primes); i = j, ++cnt) {
		ll prod = 1;
		while (j < sz(primes) && prod <= MX / primes[j]) prod *= primes[j], ++j;
		square_free[cnt] = prod;
		rep(k, i, j) groups[cnt].push_back(primes[k]);
	}

	int t; cin >> t;
	while (t--) solve();
}