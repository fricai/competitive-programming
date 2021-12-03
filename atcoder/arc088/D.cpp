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

	string s; cin >> s;
	int sum = 0;
	for (auto x : s) sum += x == '1';

	int n = sz(s);
	for (int k = n, l = 0, r = n - 1; ; ++l, --r, --k) {
		if (sum == 0 || sum == r - l + 1) {
			return cout << k << '\n', 0;
		}
		sum -= s[l] == '1';
		if (l != r) sum -= s[r] == '1';
	}
	assert(0);
}
