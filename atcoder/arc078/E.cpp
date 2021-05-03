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

bool ask(ll x) {
	cout << "? " << x << endl;
	char resp; cin >> resp;
	return resp == 'Y';
}

void print(int x) {
	cout << "! " << x << endl;
	exit(0);
}

signed main() {
	if (ask(1e10)) {
		// it is of the form 10^k
		for (ll x = 1; ; x *= 10)
			if (ask(x + 1))
				print(x);
		assert(0);
	}
	
	for (int upper = 10; ; upper *= 10) {
		if (!ask(upper)) {
			ll l = upper / 10, r = upper;
			while (r - l > 1) {
				ll m = (l + r) / 2;
				(ask(10 * m) ? r : l) = m;
			}
			
			print(r);
		}
	}
	assert(0);
}