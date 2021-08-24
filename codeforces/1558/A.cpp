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

void solve() {
	int a, b; cin >> a >> b;
	int n = a + b;

	vector<bool> vis(n + 1, false);
	auto test = [&](int x, int y) {
		x -= (n + 1) / 2;
		y -= n / 2;
		for (int k = 0; k <= n; ++k) {
			/*
			 * for (int ka = 0; ka <= n / 2; ++ka) {
				for (int kb = 0; kb <= (n + 1) / 2; ++kb) {
					if (ka + kb == k && x == ka - kb && y == kb - ka)
						vis[k] = true;
				}
			}
			*/
			if ((k + x) % 2)
				continue;
			int kx = (k + x) / 2;
			int ky = (k - x) / 2;
			if (0 <= kx && kx <= n / 2 && 0 <= ky && ky <= (n + 1) / 2)
				vis[k] = true;
			// if ((k + x) % 2)
			// 	continue;
			// if ((k + x) / 2 > n / 2)
			// 	continue;
			// if (k - x < 0)
			// 	continue;
			// if ((k - x) / 2 > (n + 1) / 2)
			// 	continue;
			// vis[k] = true;
		}
	};
	test(a, b);
	test(b, a);

	vector<int> ans;
	for (int i = 0; i <= n; ++i)
		if (vis[i])
			ans.push_back(i);

	cout << sz(ans) << '\n';
	for (auto x : ans)
		cout << x << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
