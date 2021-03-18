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

const int S = 32000;
bool vis[S];

// int mex(vector<int> v) {
// 	sort(all(v)); v.erase(unique(all(v)), end(v));
// 	for (int i = 0; i < sz(v); ++i)
// 		if (v[i] != i) return i;
// 	return sz(v);
// }

// map<ll, int> val;

// ll rem[B + 1];

// int grundy(ll state) {
// 	if (state == 0) return 0;
// 	auto it = val.find(state);
// 	if (it != end(val)) return it->second;
// 	vector<int> v;
// 	for (int i = 1; i <= B; ++i)
// 		if (state >> i & 1)
// 			v.push_back(grundy(state & ~rem[i]));
// 	return val[state] = mex(v);
// }

const int B = 29;
int g[B + 1] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// for (int i = 1; i <= B; ++i)
	// 	for (int j = i; j <= B; j += i)
	// 		rem[i] |= 1 << j;
	// ll cur = 0;
	// for (int i = 1; i <= B; ++i) {
	// 	cur |= 1 << i;
	// 	cout << grundy(cur) << ' ';
	// }

	ll n; cin >> n;
	ll rest = n - 1;

	int nim = g[1];
	for (ll d = 2; d * d <= n; ++d) {
		if (vis[d]) continue;
		int pile = 0;
		for (ll x = d; x <= n; x *= d) {
			if (x * x <= n) vis[x] = 1;
			++pile;
			--rest;
		}
		nim ^= g[pile];
		assert(pile <= B);
	}
	if (rest & 1) nim ^= g[1];
	cout << (nim ? "Vasya" : "Petya") << '\n';
}