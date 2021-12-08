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

using mint = atcoder::modint998244353;
const mint one = 1, two = 2, ten = 10, half = one / two;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string inp; cin >> inp;

	int n = sz(inp);
	vector<mint> s(n);
	rep(i, 0, n) s[i] = inp[i] - '0';
	reverse(all(s));

	vector<mint> f(n + 1);
	mint t = 0;

	mint pten = 1, phalf = 1;
	mint cur = 0, v = 0, ok = 0;

	for (int i = 1; i <= n; ++i, pten *= ten, phalf *= half) {
		t = (t + f[i - 1]) * half;
		v = v * half + ok * s[i - 1];
		cur += pten * s[i - 1];
		f[i] = t + v + cur * phalf;
		ok = ok * ten * half + half;
	}

	cout << (two.pow(n - 1) * f[n]).val() << '\n';
}
