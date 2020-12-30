#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 19, M = 1 << 19, mod = 1e9 + 7;

void add(int &a, int b) { a += b; if (mod <= a) a -= mod; }

int nxt[N];
int head(int u) { return nxt[u] ? nxt[u] = head(nxt[u]) : u; }
void join(int u, int v) {
	assert(u < v);
	u = head(u); v = head(v);
	nxt[v] = u;
}

bool taken[M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	function<bool(vector<int>)> f = [&](vector<int> v) {
		if (sz(v) != 1 && v[0] == v[1]) return false;
		sort(all(v));
		if (!taken[v.back()]) {
			taken[v.back()] = true;
			if (sz(v) != 1) join(v.front(), v.back());
			return true;
		}
		int r = head(v.back());
		if (r != v.back()) {
			v.pop_back();
			v.push_back(r);
			return f(v);
		}
		// r == v.back() and r is taken
		if (sz(v) == 1) return false;
		return f({v[0]});
	};

	vector<int> T;
	rep(i, 0, n) {
		int k; cin >> k;
		vector<int> v(k);
		for (auto &x : v) cin >> x;
		if (f(v)) T.push_back(i);
	}

	int ans = 1;
	rep(i, 0, sz(T)) add(ans, ans);
	cout << ans << ' ' << sz(T) << '\n';
	for (int x : T) cout << x + 1 << ' ';
}