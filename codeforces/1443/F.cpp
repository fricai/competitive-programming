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

const int N = 1 << 18;
int a[N], b[N], ia[N], dead[N];

const int M = (119 << 23) + 1;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		rep(i, 0, n) cin >> a[i], ia[a[i]] = i, dead[i] = 1;
		rep(i, 0, k) cin >> b[i], dead[ia[b[i]]] = 0;

		ll ans = 1;
		rep(i, 0, k) {
			int j = ia[b[i]];
			dead[j] = 1;
			int c = 0;
			if (j > 0 && dead[ia[a[j - 1]]]) ++c;
			if (j < n - 1 && dead[ia[a[j + 1]]]) ++c;
			ans = ans * c % M;
		}
		cout << ans << '\n';
	}
}