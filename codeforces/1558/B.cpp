#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
void inc(int &x, int y) { x += y; if (x >= m) x -= m; }
void dec(int &x, int y) { x -= y; if (x < 0) x += m; }
int add(int x, int y) { return x += y, x < m ? x : x - m; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	vector<int> f(n + 1), g(n + 1);
	g[1] = 1;

	int tot = 1;
	for (int i = 1; i <= n; ++i) {
		if (i > 1) {
			inc(f[i], f[i - 1]);
			inc(g[i], tot);
		}

		int cur = add(f[i], g[i]);
		for (int k = 2 * i, r = 2; k <= n; k += i, ++r) {
			inc(f[k], cur);
			if (k + r <= n)
				dec(f[k + r], cur);
		}
		if (i > 1)
			inc(tot, cur);
	}

	cout << add(f[n], g[n]) << '\n';
}
