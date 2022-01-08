#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int mod = 998244353, A = 26;
using mint = atcoder::static_modint<mod>;
using poly = vector<mint>;

constexpr int N = 5000 + 10;
mint f[N], fi[N];

poly constr(int k) { return {fi, fi + k + 1}; };

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = 1;
	rep(i, 1, N) f[i] = mint::raw(i) * f[i - 1];
	fi[N - 1] = 1 / f[N - 1];
	per(i, 1, N) fi[i - 1] = mint::raw(i) * fi[i];

	string s; cin >> s;
	array<int, A> freq = {};
	for (auto c : s) ++freq[c - 'a'];

	poly res = {1};
	rep(i, 0, A) res = atcoder::convolution(res, constr(freq[i]));

	mint ans = 0;
	rep(i, 1, sz(res)) ans += f[i] * res[i];
	cout << ans.val() << '\n';
}
