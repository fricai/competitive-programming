#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	string s; cin >> s;
	rep(i, 1, n) if (s[i] == '1' && s[i - 1] == '1') return cout << "No", 0;
	rep(i, 0, n) {
		if (s[i] != '0') continue;
		bool ok = true;
		if (i > 0 && s[i - 1] == '1') ok = false;
		if (i < n - 1 && s[i + 1] == '1') ok = false;
		if (ok) return cout << "No", 0;
	}
	cout << "Yes";
}