#include <bits/stdc++.h>
#include <atcoder/all>

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

const int N = 1 << 11;
int a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, q; cin >> n >> k >> q;

	vector<int> cmp;
	rep(i, 0, n) cin >> a[i], cmp.push_back(a[i]);
	sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));

	int ans = 2e9;
	for (auto Y : cmp) {
		int i = 0;
		while (i < n && a[i] < Y) ++i;

		vector<int> opt;
		for (int j = i; i < n; i = j) {
			assert(a[i] >= Y);
			while (j < n && a[j] >= Y) ++j;
			vector<int> res;
			rep(k, i, j) res.push_back(a[k]);
			sort(all(res));
			while (sz(res) > max(0, j - i - k + 1)) res.pop_back();
			for (auto x : res) opt.push_back(x);
			while (j < n && a[j] < Y) ++j;
		}

		sort(all(opt));
		if (sz(opt) >= q) ckmin(ans, opt[q - 1] - Y);
	}
	cout << ans;
}