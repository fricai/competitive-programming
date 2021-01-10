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


const int N = 1 << 18;
ll a[N], b[N], c[N];
ll sum[N << 1];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll C; int n; cin >> n >> C;
	vector<int> cmp = {0};
	rep(i, 0, n) {
		cin >> a[i] >> b[i] >> c[i];
		++b[i];
		cmp.push_back(a[i]);
		cmp.push_back(b[i]);
	}
	sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));
	rep(i, 0, n) {
		a[i] = lb(all(cmp), a[i]) - begin(cmp);
		b[i] = lb(all(cmp), b[i]) - begin(cmp);
		sum[a[i]] += c[i];
		sum[b[i]] -= c[i];
	}

	ll cur = 0; ll ans = 0;
	rep(i, 1, sz(cmp)) {
		ans += min(cur, C) * (cmp[i] - cmp[i - 1]);
		cur += sum[i];
	}
	cout << ans;
}