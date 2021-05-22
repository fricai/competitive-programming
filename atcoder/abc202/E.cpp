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


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

template<class T>
using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1 << 18;
vector<int> g[N];
ost<pair<int, int>> s[N];
int dep[N];

int less_count(ost<pair<int, int>> &s, int k) {
	return s.order_of_key({k + 1, -1});
}

int count(ost<pair<int, int>> &s, int k) {
	return less_count(s, k) - less_count(s, k - 1);
}

template<class T>
void merge(ost<T> &a, ost<T> &b) {
	if (sz(a) < sz(b)) a.swap(b);
	for (auto x : b) a.insert(x);
}

const int Q = N;
int ans[Q];
vector<pair<int, int>> ev[N];
void dfs(int u) {
	s[u].insert({dep[u], u});
	for (int v : g[u]) {
		dep[v] = dep[u] + 1;
		dfs(v);
		merge(s[u], s[v]);
	}


	for (auto [d, i] : ev[u])
		ans[i] = count(s[u], d);	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	int n; cin >> n;
	rep(u, 1, n) {
		int p; cin >> p;
		g[p - 1].push_back(u);
	}

	int q; cin >> q;
	rep(i, 0, q) {
		int u, d; cin >> u >> d;
		--u;
		ev[u].emplace_back(d, i);
	}
	dfs(0);

	rep(i, 0, q) cout << ans[i] << '\n';
}