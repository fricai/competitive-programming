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

void solve() {
	int n; cin >> n;
	vector<int> p(n), pi(n);
	for (auto &x : p) cin >> x, --x;
	rep(i, 0, n) pi[p[i]] = i;

	string s; cin >> s;

	int z = count(all(s), '0'), o = n;

	vector<int> q(n);
	per(i, 0, n) {
		int j = pi[i];
		if (s[j] == '0') {
			q[j] = z--;
		} else {
			q[j] = o--;
		}
	}

	for (auto x : q)
		cout << x << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
