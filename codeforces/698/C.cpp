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

const int N = 20;
const ld eps = 1e-9;
ld f[1 << N], p[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, n; cin >> n >> k;
	rep(i, 0, n) cin >> p[i];

	cout << fixed << setprecision(10);
	rep(i, 0, n) {
		if (p[i] < eps) { cout << 0.0 << ' '; continue; }
		f[0] = p[i];
		ld res = p[i];
		rep(S, 1, 1 << n) {
			if (S >> i & 1) continue;
			f[S] = 0;
			ld d = 1;
			rep(j, 0, n) if (S >> j & 1) f[S] += p[j] * f[S ^ (1 << j)], d -= p[j];
			f[S] /= d;
			if (__builtin_popcount(S) < k) res += f[S];
		}
		cout << res << ' ';
	}
	cout << '\n';
}