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

const int N = 5000 + 10;
ll x[N], y[N];
int q[N];
bool dead[N];
ll d[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> x[i] >> y[i];

	ll mx = 0;
	ll a, b;
	rep(i, 0, n) {
		rep(j, 0, i) {
			a = x[i] - x[j];
			b = y[i] - y[j];
			d[i][j] = a * a + b * b; 
			if (ckmax(mx, d[i][j])) q[0] = i, q[1] = j;
		}
	}
	rep(i, 0, n) rep(j, i + 1, n) d[i][j] = d[j][i];
	dead[q[0]] = dead[q[1]] = 1;

	rep(i, 2, n) {
		mx = 0;
		int cur = q[i - 1], nxt = -1;
		rep(j, 0, n) if (!dead[j] && ckmax(mx, d[cur][j])) nxt = j;
		assert(nxt != -1);
		q[i] = nxt;
		dead[nxt] = 1;
	}
	rep(i, 0, n) cout << q[i] + 1 << ' ';
}