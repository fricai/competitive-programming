#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c; cin >> a >> b >> c;

	int x = 0, y = 0;
	while (a % 2 == 0) ++x, a /= 2;
	while (a % 5 == 0) ++y, a /= 5;

	using m10 = static_modint<10>;
	using m4 = static_modint<4>;

	int k = m4(b).pow(c).val();
	m10 ans = m10(a).pow(k);
	if (k == 0) k = 4;

	if (x > 0) ans *= m10(2).pow(x * k);
	if (y > 0) ans *= 5;

	cout << ans.val() << '\n';
}
