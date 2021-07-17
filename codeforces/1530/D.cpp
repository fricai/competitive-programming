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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x, --x;
	vector<int> col(n), indeg(n);
	
	for (auto x : a)
		++indeg[x];

	/*
		0 -> unvisited
		1 -> active
		2 -> visited, part of chain
		3 -> visited, part of cycle
	*/

	vector<int> b(n, -1);

	int lst = -1, fst = -1;
	for (int u = 0; u < n; ++u) {
		if (indeg[u] != 0) continue;
		
		if (fst < 0) fst = u;
		
		int v = u;
		
		while (col[v] == 0) {
			col[v] = 1;
			v = a[v];
		}

		int w = u;
		while (a[w] != v) {
			col[w] = 2;
			w = a[w];
		}
		col[w] = 2;
		
		if (lst >= 0) b[lst] = u;
		lst = w;
		
		while (col[v] == 1) {
			col[v] = 3;
			v = a[v];
		}
	}

	if (fst != -1) {
		if (fst == lst) {
			int v = fst;
			col.assign(n, 0);
			while (col[a[v]] == 0) {
				b[v] = a[v];
				col[v] = 1;
				v = a[v];
			}
			b[v] = fst;
		} else
			b[lst] = fst;
	}
	
	rep(i, 0, n) if (b[i] < 0) b[i] = a[i];
	
	int k = 0;
	rep(i, 0, n) k += a[i] == b[i];
	
	cout << k << '\n';
	for (auto x : b) cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}