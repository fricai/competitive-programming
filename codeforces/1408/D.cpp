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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 11, X = 1 << 20;
int a[N], b[N], c[N], d[N];
int t[X << 1];

void modify(int l, int r, int value) {
  for (l += X, r += X; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ckmax(t[l++], value);
    if (r & 1) ckmax(t[--r], value);
  }
}

int query(int p) {
  int res = 0;
  for (p += X; p > 0; p >>= 1) ckmax(res, t[p]);
  return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> a[i] >> b[i];
	rep(i, 0, m) cin >> c[i] >> d[i];
	rep(i, 0, n)
		rep(j, 0, m)
			modify(0, c[j] - a[i] + 1, d[j] - b[i] + 1);
	int ans = 1e9;
	rep(p, 0, X) ckmin(ans, query(p) + p);
	cout << ans;
}