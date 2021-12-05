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

constexpr int A = 26;
using mint = atcoder::modint1000000007;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	int n = sz(s);

	vector<int> p(A);
	vector<mint> f(n + 3);
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;

	for (int i = 1; i <= n; ++i) {
		int &j = p[s[i - 1] - 'a'];
		f[i + 2] = f[i + 1] + f[i] - f[j];
		j = i;
	}
	cout << (f.back() - 1).val() << '\n';
}
