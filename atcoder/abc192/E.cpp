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

const ll inf = 1e18;
const int N = 1 << 17, M = N;
vector<int> g[N];

ll d[N + M + M];
int a[M], b[M], t[M], k[M];

ll nxt(ll t, ll k) { return (t + k - 1) / k * k; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, x, y; cin >> n >> m >> x >> y; --x; --y;
	rep(e, 0, m) {
		cin >> a[e] >> b[e] >> t[e] >> k[e]; --a[e], --b[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}

	fill(d, d + n + m + m, inf);
    d[x + m + m] = 0;

    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0ll, x + m + m});

    while (!q.empty()) {
		auto [d_u, u] = q.top();
		// cerr << u << ' ' << d_u << '\n';

        q.pop();
        if (d_u != d[u]) continue;
		if (u < m + m) {
			int x;
			if (u < m) {
				if (ckmin(d[u + m], nxt(d[u], k[u]) + t[u])) q.push({d[u + m], u + m});
				x = a[u] + m + m;
			} else {
				if (ckmin(d[u - m], nxt(d[u], k[u - m]) + t[u - m])) q.push({d[u - m], u - m});
				x = b[u - m] + m + m;
			}
			if (ckmin(d[x], d[u])) q.push({d[x], x});
		} else {
			u -= 2 * m;
			// cerr << "ahoy";
			for (auto e : g[u]) {
				int v = a[e] == u ? e : e + m;
				if (ckmin(d[v], d[u + m + m])) q.push({d[v], v});
			}
		}
    }

	// rep(u, 0, m + m + n) cerr << d[u] << ' ';

	cout << (d[y + m + m] < inf ? d[y + m + m] : -1);
}