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

const int N = 1 << 17;
pair<int, int> l[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> l[i].first;

	ll after = 0, before = 0;
	rep(i, 0, n) cin >> l[i].second, after += l[i].second;
	sort(l, l + n);
	
	ll ans = after;
	multiset<int> mn;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && l[i].first == l[j].first) ++j;
		rep(k, i, j) after -= l[k].second;

		ll cur = after + before;
		int cnt = 1;
		for (auto it = mn.rbegin(); it != mn.rend() && cnt < j - i; ++it, ++cnt)
			cur -= *it;
		ckmin(ans, cur);

		rep(k, i, j) before += l[k].second, mn.insert(l[k].second);
	}
	cout << ans << '\n';
}