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

const int N = 1 << 9;
int a[N][N];

vector<int> val;
vector<pair<int, int>> edges;
int rec(vector<int> opt) {
	if (sz(opt) == 1) return opt.back();

	int mx = 0;
	for (auto x : opt) for (auto y : opt) ckmax(mx, a[x][y]);

	int root = sz(val);
	val.push_back(mx);

	vector<vector<int>> children;
	for (auto x : opt) {
		bool placed = false;
		for (auto &subtree : children) {
			if (a[subtree.back()][x] != mx) {
				placed = true;
				subtree.push_back(x);
				break;
			}
		}
		if (!placed) children.push_back({x});
	}
	for (auto &subtree : children)
		edges.emplace_back(rec(subtree) + 1, root + 1);
	return root;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
	vector<int> opt(n);
	rep(i, 0, n) {
		opt[i] = i;
		val.push_back(a[i][i]);
	}
	rec(opt);

	cout << sz(val) << '\n';
	for (auto x : val) cout << x << ' ';
	cout << '\n' << n + 1 << '\n';
	for (auto [u, v] : edges) cout << u << ' ' << v << '\n';
}