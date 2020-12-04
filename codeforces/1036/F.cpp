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

const int T = 1 << 17, X = 1 << 20;
ll ans[T], z[X];
int mu[] = {0, 1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1, -1, 0, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1, 0, -1, 1, 0, 0, 1, -1, -1, 0, 1, -1, -1, 0, -1, 1, 0, 0, 1, -1};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll mx = 0;
	vector<pair<ll, int>> v;

	int t; cin >> t;
	rep(i, 0, t) {
		ll n; cin >> n; ckmax(mx, n);
		v.emplace_back(n, i);
		ans[i] += (n - 1) * mu[1] + (floor(sqrt(n)) - 1) * mu[2];
	}
	sort(all(v));

	rep(i, 0ll, X) z[i] = i * i * i;

	int x = X, j = 3;
	while (x != 2) {
		// cerr << x << '\n';
		int k = 0;
		for (auto &[n, i] : v) {
			while (z[k] <= n) ++k;
			ans[i] += (k - 2) * mu[j];
		}
		rep(k, 2, x) {
			z[k] *= k;
			if (z[k] > mx) {
				x = k;
				break;
			}
		}
		++j;
	}

	rep(i, 0, t) cout << ans[i] << '\n';
}