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
int l[N], d[N], ord[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> l[i], ord[i] = i;

	ll after = 0, before = 0;
	rep(i, 0, n) cin >> d[i], after += d[i];
	sort(ord, ord + n, [&](int x, int y) { return l[x] < l[y]; });
	
	ll ans = after;

	multiset<int> mn;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && l[ord[i]] == l[ord[j]]) ++j;
		rep(k, i, j) after -= d[ord[k]];

		ll cur = after + before;
		int cnt = 1;
		for (auto it = mn.rbegin(); it != mn.rend() && cnt < j - i; ++it, ++cnt)
			cur -= *it;
		ckmin(ans, cur);

		rep(k, i, j) before += d[ord[k]], mn.insert(d[ord[k]]);
	}
	cout << ans << '\n';
}