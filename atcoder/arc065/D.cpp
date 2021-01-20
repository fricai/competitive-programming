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

const int N = 1 << 18;
int n;
struct dsu {
	vector<int> nxt;
	dsu(int n) : nxt(n) { iota(all(nxt), 0); }
	int head(int u) { return nxt[u] != u ? nxt[u] = head(nxt[u]) : u; }
	void join(int u, int v) { nxt[head(u)] = head(v); }
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, l; cin >> n >> k >> l;

	dsu d1(n), d2(n);
	rep(e, 0, k) {
		int u, v; cin >> u >> v; --u; --v;
		d1.join(u, v);
	}
	rep(e, 0, l) {
		int u, v; cin >> u >> v; --u; --v;
		d2.join(u, v);
	}
	map<pair<int, int>, int> m;
	rep(u, 0, n) m[{d1.head(u), d2.head(u)}]++;	
	rep(u, 0, n) cout << m[{d1.head(u), d2.head(u)}] << ' ';
}