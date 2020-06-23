#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 2 << 20;
const ll M = 1e9 + 7;
ll f[N], g[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto val = [&](int i) { return i % 3 ? g[i] : f[i]; };
	rep(i, 2, N) {
		f[i] = (4 + g[i - 1] + 2 * g[i - 2]) % M;
		g[i] = (val(i - 1) + 2 * val(i - 2)) % M;
	}
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		cout << val(x) << '\n';
	}
}