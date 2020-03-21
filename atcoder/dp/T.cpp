#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define ff first
#define ss second

using ll = int64_t;

const int M = 1e9 + 7;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using vi = vector<int>;
using vvi = vector<vi>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n; vi f(n), s(n + 1);
	string x; cin >> x;
	f[0] = 1;
	rep(i, 0, n - 1) {
		vi g(n);
		rep(i, 0, n) s[i + 1] = (s[i] + f[i]) % M;
		if (x[i] == '<')
			rep(j, 0, i + 2) g[j] = s[j];
		else
			rep(j, 0, i + 2) g[j] = (s[n] - s[j]) % M;
		swap(f, g);
	}
	int ans = 0;
	trav(z, f) (ans += z) %= M;
	if (ans < 0) ans += M;
	cout << ans;
}