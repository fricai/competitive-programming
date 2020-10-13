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

int solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> v;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && s[i] == s[j]) ++j;
		v.eb(j - i);
	}
	reverse(all(v));
	int ans = 0;
	int t = sz(v) - 1;
	while (t >= 0 && !v.empty()) {
		while (t >= sz(v)) --t;
		while (t >= 0 && v[t] == 1) --t;
		if (t < 0) break;
		--v[t]; v.pop_back();
		++ans;
	}
	return ans + (sz(v) + 1) / 2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}