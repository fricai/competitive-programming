#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll A = 26;
int fixed_mod(ll a, int b) {
	return (a + b - 1) % b + 1;
}

void recur(ll n) {
	if (n <= 0) return;
	recur((n - fixed_mod(n, A)) / A);

	// cout << n << ": ";
	cout << char('a' + fixed_mod(n, A) - 1);
	// cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n; cin >> n;
	recur(n);
}