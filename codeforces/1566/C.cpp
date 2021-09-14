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

int solve() {
	int n; cin >> n;
	string s, t; cin >> s >> t;

	vector<int> count(n);
	rep(i, 0, n) count[i] = (s[i] == '1') + (t[i] == '1');

	int ans = 0;
	for (int i = 0, j = 0; i < n; i = j) {
		if (count[i] == 0) {
			if (i + 1 < n && count[i + 1] == 2) {
				j += 2;
				ans += 2;
			} else {
				++j;
				ans += 1;
			}
		} else if (count[i] == 1) {
			ans += 2;
			++j;
		} else {
			if (i + 1 < n && count[i + 1] == 0) {
				j += 2;
				ans += 2;
			} else ++j;
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
