#include <bits/stdc++.h>

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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> f(n);
	rep(i, 0, n) {
		int x; cin >> x;
		++f[x - 1];
	}

	vector<int> g(n + 1);
	rep(i, 0, n) ++g[f[i]];

	ll sum = accumulate(all(g), 0ll) - g[0];
	ll dsum = 0;

	vector<int> b(n + 1);
	b[0] = n;
	for (int x = 1; x <= n; ++x) {
		dsum += x * g[x];
		sum -= g[x];
		b[x] = dsum / x + sum;
	}

	for (int k = 1, x = n; k <= n; ++k) {
		while (k > b[x]) --x;
		cout << x << '\n';
	}
}
