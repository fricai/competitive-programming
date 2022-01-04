#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
	int n; cin >> n;
	string s; cin >> s;

	int ans = n + 1;
	rep(i, 0, n) {
		int c[3] = {};
		for (int j = i; j < n && j - i <= 20; ++j) {
			++c[s[j] - 'a'];
			if (j - i + 1 >= 2 && c[0] > c[1] && c[0] > c[2]) {
				uin(ans, j - i + 1);
			}
		}
	}
	return ans <= n ? ans : -1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
