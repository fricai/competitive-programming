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

	int fst = -1, lst = n;
	per(i, 0, n) if (s[i] != '.') fst = i;
	if (fst < 0) return cout << n, 0;
	rep(i, 0, n) if (s[i] != '.') lst = i;
	assert(lst < n);

	int ans = 0;
	if (s[fst] == 'R') ans += fst;
	if (s[lst] == 'L') ans += n - lst - 1;
	
	int pre = s[fst] == 'L' ? -1 : fst;
	int bk = s[lst] == 'R' ? lst - 1 : lst;
	for (int i = fst + 1; i <= bk; ++i) {
		if (s[i] == 'R') pre = i;
		else if (s[i] == 'L') {
			assert(pre != -1);
			if ((i - pre + 1) % 2) ++ans;
			pre = -1;
		} else {
			if (pre == -1) ++ans;
		}
	}
	cout << ans;
}