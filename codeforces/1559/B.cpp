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

string solve() {
	int n; cin >> n;
	string s; cin >> s;
	int first = 0;
	while (first < n && s[first] == '?')
		++first;

	char flip = 'B' ^ 'R';
	char init = first == n ? 'B' : s[first];
	while (first > 0) {
		--first;
		init ^= flip;
		s[first] = init;
	}

	rep(i, 0, n) {
		if (s[i] != '?')
			continue;
		s[i] = s[i - 1] ^ flip;
	}
	return s;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
