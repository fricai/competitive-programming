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

const int N = 1 << 19;
int l[N], r[N];
int ord[N];

int f(int i) { return r[i] - l[i]; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> l[i] >> r[i], --l[i], ord[i] = i;
	sort(ord, ord + n, [&](int i, int j) {
		return f(i) < f(j);
	});

	ost<pair<int, int>> L, R;
	for (int d = 1, i = 0; d <= m; ++d) {
		while (i < n && f(ord[i]) <= d) {
			L.insert({l[ord[i]], i});
			R.insert({r[ord[i]], i});
			++i;
		}
		int res = n - i;
		for (int q = 0; q <= m; q += d)
			res += L.order_of_key({q, -1}) - R.order_of_key({q, -1});
		cout << res << '\n';
	}
}