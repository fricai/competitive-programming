#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, m, k; cin >> n >> m >> k;

	bool flipped = 0;	
	if (n & 1) {
		flipped = 1;
		swap(n, m);
		k = (n * m) / 2 - k;
	}

	if ((k & 1) || ((m & 1) && (k > n / 2 * (m - 1))))
		return cout << "NO\n", void();
	
	int counter = 0;
	vector  g(n, vector(m, 0));
	
	for (int j = 0; j < m; j += 2) {
		for (int i = 0; i < n; i += 2) {
			if (k > 0) {
				g[i][j] = counter;
				g[i][j + 1] = counter;
				g[i + 1][j] = counter + 1;
				g[i + 1][j + 1] = counter + 1;

				counter += 2;
				k -= 2;
			} else {
				g[i][j] = counter;
				g[i + 1][j] = counter;
				
				++counter;
				
				if (j + 1 < m) {
					g[i][j + 1] = counter;
					g[i + 1][j + 1] = counter; 
					++counter;
				}
			}
		}
	}

	if (flipped) {
		vector f(m, vector(n, 0));
		rep(i, 0, n)
			rep(j, 0, m)
				f[j][i] = g[i][j];
		swap(f, g);
		swap(n, m);
	}

	cout << "YES\n";
	char s[2][2] = {'a', 'b', 'c', 'd'};
	
	rep(i, 0, n) {
		rep(j, 0, m)
			cout << s[(i / 2 + j / 2) & 1][g[i][j] & 1];
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while (t--) solve();
}