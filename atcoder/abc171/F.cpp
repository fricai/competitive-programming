#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using mint = atcoder::modint1000000007;
constexpr int N = 2e6 + 5, A = 26;
mint f[N], fi[N], ap[N], api[N];
mint C(int n, int r) {
	if (r < 0 || r > n) return 0;
	return f[n] * fi[r] * fi[n - r];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = ap[0] = api[0] = 1;
	rep(i, 1, N) {
		f[i] = i * f[i - 1];
		ap[i] = A * ap[i - 1];
		api[i] = (A - 1) * api[i - 1];
	}
	fi[N - 1] = 1/f[N - 1];
	per(i, 1, N) fi[i - 1] = i * fi[i];

	int k; cin >> k;
	string s; cin >> s;

	int n = sz(s);
	mint ans = 0;
	for (int x = n - 1; x < n + k; ++x) {
		ans += C(x, n - 1) * api[x - n + 1] * ap[n + k - x - 1];
	}
	cout << ans.val() << '\n';
}

