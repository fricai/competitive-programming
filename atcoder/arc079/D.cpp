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

	ll k; cin >> k;
	const int n = 50;

	vector<ll> res(n);
	iota(all(res), 0);
	
	rep(i, 0, n) res[i] += k / n;
	int left = k % n;
	rep(i, 0, left) {
		res[i] += n;
		rep(j, 0, n) if (j != i) --res[j];
	}

	cout << n << '\n';
	for (auto x : res) cout << x << ' ';
	cout << '\n';
}