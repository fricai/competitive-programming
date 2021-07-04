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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; ll k; cin >> n >> k;
	
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });

	vector<ll> ans(n, k / n);
	k %= n;
	rep(i, 0, k) ++ans[ord[i]];

	for (auto x : ans) cout << x << '\n';
}