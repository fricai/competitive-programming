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

const int N = 3e5 + 10, M = 1e9 + 7;
ll x[N];

void add(int &x, int y) { x += y; if (M <= x) x -= M; }
void sub(int &x, int y) { x -= y; if (x < 0) x += M; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> x[i];
	sort(x, x + n);

	int ans = 0, cur = 0, p = 1;
	for (int r = 0; r < n; ++r) {
		add(ans, (p - 1) * x[r] % M);
		sub(ans, cur);
		add(cur, cur);
		add(cur, x[r]);
		add(p, p);
	}
	cout << ans << '\n';
}