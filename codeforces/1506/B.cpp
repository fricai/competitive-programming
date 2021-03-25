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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	int cnt = 0;
	int l = -1, r = -1;
	auto f = [&](int i) {
		assert(i < n);
		if (s[i] != 'X') {
			assert(s[i] == '*');
			s[i] = 'X', ++cnt;
		}
	};
	rep(i, 0, n) if (s[i] == '*') { f(i), l = i; break; }
	if (l < 0) assert(0);

	per(i, 0, n) if (s[i] == '*') { f(i), r = i; break; }


	rep(i, l, r) {
		if (s[i] != 'X') continue;
		bool exists = 0;
		int lst = -1;
		for (int j = i + 1; j <= i + k && j <= r; ++j) {
			exists |= s[j] == 'X';
			if (s[j] == '*') lst = j;
		}
		
		if (!exists) {
			assert(lst >= 0);
			f(lst);
		}
	}
	return cnt;
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}