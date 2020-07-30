#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

vector<int> solve() {
	int n; cin >> n;
	if (n <= 30) return { };
	if (n != 36 && n != 40 && n != 44)
		return {6, 10, 14, n - 30};
	return {6, 10, 15, n - 31};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		auto v = solve();
		if (v.empty()) cout << "NO\n";
		else {
			cout << "YES\n";
			trav(x, v) cout << x << ' '; cout << '\n';
		}
	}
}