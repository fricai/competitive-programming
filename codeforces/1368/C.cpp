#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using pii = pair<int, int>;
set<pii> ans;

void recur(int root, int n) {
	if (n < 0) ans.insert({root, root});
	else {
		ans.insert({root, root});
		ans.insert({root + 1, root});
		ans.insert({root, root + 1});
		recur(root + 1, n - 1);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	recur(0, n);
	cout << ans.size() << '\n';
	trav(x, ans) cout << x.first << ' ' << x.second << '\n';
}