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

const int N = 1 << 7;
int a[N], b[N], c[N], p[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		rep(i, 0, n) cin >> a[i];
		rep(i, 0, n) cin >> b[i];
		rep(i, 0, n) cin >> c[i];
		p[0] = a[0];
		rep(i, 1, n - 1) {
			if (p[i - 1] != a[i]) p[i] = a[i];
			if (p[i - 1] != b[i]) p[i] = b[i];
			if (p[i - 1] != c[i]) p[i] = c[i];
		}
		if (p[n - 2] != a[n - 1] && p[0] != a[n - 1]) p[n - 1] = a[n - 1];
		if (p[n - 2] != b[n - 1] && p[0] != b[n - 1]) p[n - 1] = b[n - 1];
		if (p[n - 2] != c[n - 1] && p[0] != c[n - 1]) p[n - 1] = c[n - 1];
		rep(i, 0, n) cout << p[i] << ' ';
		cout << '\n';
	}
}