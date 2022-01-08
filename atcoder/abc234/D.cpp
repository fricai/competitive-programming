#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<class T>
using ost = __gnu_pbds::tree<T, __gnu_pbds::null_type, greater<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n, k; cin >> n >> k;
	vector<int> p(n);
	for (auto &x : p) cin >> x;

	ost<int> s;
	rep(i, 0, n) {
		s.insert(p[i]);
		// [0, i] => i + 1 elements
		if (i + 1 >= k) cout << *s.find_by_order(k - 1) << '\n';
	}
}
