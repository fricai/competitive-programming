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

const int M = (119 << 23) + 1;
const int N = 1 << 19;
ll inv[N], f[N], fi[N];

int nCr(int n, int r) {
	if (r < 0 || r > n) return 0;
	return f[n] * fi[r] % M * fi[n - r] % M;
}

template<class S, class T> S& add(S &a, const T& b) { a += b; if (M <= a) a -= M; return a; }
template<class S, class T> S& sub(S &a, const T& b) { a -= b; if (a < 0) a += M; return a; }

int solve() {
	int n, k; cin >> n >> k;
	vector<int> E;
	rep(i, 0, n) {
		int l, r; cin >> l >> r;
		E.eb(l << 1|0);
		E.eb(r << 1|1);
	}
	sort(all(E));
	int dep = 0, ans = 0;
	for (int r = 0; r < sz(E); ) {
		int l = r;
		while (r < sz(E) && E[l] == E[r]) ++r;
		if (E[l] & 1) dep -= r - l;
		else sub(add(ans, nCr(dep + r - l, k)), nCr(dep, k)), dep += r - l;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = f[1] = fi[0] = fi[1] = inv[1] = 1;
	rep(i, 2, N) {
		inv[i] = (M - (M / i) * inv[M % i] % M) % M;
		f[i] = i * f[i - 1] % M;
		fi[i] = inv[i] * fi[i - 1] % M;
	}
	
	cout << solve() << '\n';
}