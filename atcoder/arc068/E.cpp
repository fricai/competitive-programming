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

const int N = 1 << 19, M = 1 << 17;
int l[N], r[N];
int ord[N];
int t[M << 1];

void modify(int l, int r) {
	for (l |= M, r |= M; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ++t[l++];
		if (r & 1) ++t[--r];
	}
}

int query(int p) {
	int res = 0;
	for (p |= M; p; p >>= 1) res += t[p];
	return res;
}

int f(int i) { return r[i] - l[i]; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> l[i] >> r[i], ++r[i], ord[i] = i;
	sort(ord, ord + n, [&](int i, int j) {
		return f(i) < f(j);
	});

	ost<pair<int, int>> L, R;
	for (int d = 1, i = 0; d <= m; ++d) {
		while (i < n && f(ord[i]) <= d) modify(l[ord[i]], r[ord[i]]), ++i;

		int res = n - i;
		for (int q = 0; q <= m; q += d)
			res += query(q);
		cout << res << '\n';
	}
}