#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz(x...) resize(x)
#define ins(x...) insert(x) 
#define ft() front()
#define bk() back()
#define pf(x) push_front(x) 
#define pb(x) push_back(x)
#define eb(x...) emplace_back(x)
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)
#define ff first
#define ss second

#define rep(i, a, b) for (auto i = (a); i < (b); ++i) // [a, b)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i) // (b, a]
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template <class T> using ost = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key
#define fbo find_by_order

ll f(ll h) {
	return h * (3 * h + 1) / 2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll h = 1;
		while (f(h) <= n) ++h;
		int cnt = 0;
		while (h > 0) {
			while (n >= f(h)) {
				n -= f(h);
				++cnt;
			}
			--h;
		}
		cout << cnt << '\n';
	}
}