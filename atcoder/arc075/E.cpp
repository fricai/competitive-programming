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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ost<pair<ll, int>> s;
	s.insert({0, 0});
	ll ans = 0, sum = 0;

	int n; ll k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		sum += x;
		// for (auto [x, y] : s)
		// 	if (x <= sum - k * i)
		// 		++ans;
		ans += s.order_of_key({sum - k * i + 1, -1});
		s.insert({sum - k * i, i});
	}
	cout << ans;
}