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

const int N = 1 << 17, M = 6;
int a[N], b[N], f[N];
pair<int, int> v[N * M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 0, M) cin >> a[i];
	int n; cin >> n;
	rep(i, 0, n) cin >> b[i];
	
	int p = 0;
	rep(i, 0, n) rep(j, 0, M) v[p++] = {b[i] - a[j], i};
	sort(v, v + p);
	
	multiset<int> t;
	int ans = 2e9;
	for (int l = 0, r = 0, cnt = 0; l < p; ++l) {
		while (r < p && cnt < n) {
			auto [a, b] = v[r++];
			if (f[b]++ == 0) ++cnt;
			t.insert(a);
		}
		
		if (cnt < n) break;
		
		ckmin(ans, *t.rbegin() - *t.begin());
		
		auto [a, b] = v[l];
		if (--f[b] == 0) --cnt;
		t.erase(t.find(a));
	}
	cout << ans;
}