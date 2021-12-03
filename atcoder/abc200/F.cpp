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
const mint half = mint(1) / 2;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	ll k; cin >> k;
	mint ans = 0;

	int q = 0;
	for (int i = 0; i < sz(s); ++i) {
		char c = s[i];
		char d = i + 1 == sz(s) ? s[0] : s[i + 1];

		q += c == '?';
		if (c == '?' || d == '?')
			ans += half;
		else if (c != d)
			++ans;
	}

	ans *= k;
	ans *= mint(2).pow(k * q);
	ans *= half;

	cout << (k * q != 1 ? ans.val() : 0) << '\n';
}
