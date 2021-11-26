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

	int k, n; cin >> k >> n;

	if (~k & 1) {
		cout << k / 2 << ' ';
		rep(i, 1, n) cout << k << ' ';
		cout << '\n';
		return 0;
	}

	vector<int> s(n, (k + 1) / 2);
	rep(i, 0, n / 2) {
		assert(!s.empty());
		if (s.back() == 1) {
			s.pop_back();
		} else {
			--s.back();
			while (sz(s) < n)
				s.push_back(k);
		}
	}

	for (auto x : s)
		cout << x << ' ';
	cout << '\n';
}
