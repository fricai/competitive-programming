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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<stack<int>> nxt(n + 1, stack<int>({n}));
	per(i, 0, n) nxt[a[i]].push(i);
	int x = 0, y = 0;

	int ans = 0;

	for (auto z : a) {
		if (x == z) {
			if (y != z) y = z, ++ans;
		} else if (y == z) x = z, ++ans;
		else {
			if (nxt[x].top() < nxt[y].top()) x = z;
			else y = z;
			++ans;
		}
		nxt[z].pop();
	}
	cout << ans;
}