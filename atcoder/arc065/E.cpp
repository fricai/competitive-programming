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

const int N = 1 << 17;
int x[N], y[N];
int ord[N];

struct dsu {
	vector<int> nxt;
	dsu(int n) : nxt(n) { iota(all(nxt), 0); }
	int head(int u) { return nxt[u] != u ? nxt[u] = head(nxt[u]) : u; }
	void join(int u, int v) { nxt[head(u)] = head(v); }
};
int deg[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b; cin >> n >> a >> b; --a; --b;
	rep(i, 0, n) cin >> x[i] >> y[i];
	int d = abs(x[a] - x[b]) + abs(y[a] - y[b]);

	dsu D(n);
	rep(_, 0, 4) {
		rep(i, 0, n) tie(x[i], y[i]) = pair(-y[i], x[i]);

		rep(i, 0, n) ord[i] = i;
		sort(ord, ord + n, [&](int i, int j) {
			return pair(x[i] + y[i], x[i]) < pair(x[j] + y[j], x[j]);
		});
		
		set<int> s;
		rep(i, 0, n) s.insert(i);
		s.insert(n);

		int a = 0, b = 0;
		rep(i, 0, n) {
			int r = x[ord[i]] + y[ord[i]] + d;
			while (a < n && pair(r, x[ord[i]]) > pair(x[ord[a]] + y[ord[a]], x[ord[a]])) ++a;
			while (b < n && pair(r, -y[ord[i]]) > pair(x[ord[b]] + y[ord[b]], -y[ord[b]])) ++b;
			
			if (a == b) continue;
			deg[ord[i]] += b - a;
			D.join(ord[i], ord[a]);
			for (auto it = s.ub(a); *it < b; ) s.erase(it++);
		}

		for (auto i = begin(s), j = next(begin(s)); j != end(s); ++i, ++j)
			rep(k, *i, *j) D.join(ord[*i], ord[k]);
	}
	
	ll ans = 0;
	rep(u, 0, n) if (D.head(u) == D.head(a)) ans += deg[u];
	cout << ans / 2;
}