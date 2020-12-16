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

const int N = 1 << 12;
int a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll s = 0;
		rep(i, 0, n) cin >> a[i], s += a[i];
		rep(k, 0, n) {
			ll target = s / (n - k);
			if (target * (n - k) != s) continue;
			if ([&]() {
				for (int i = 0, j = 0; i < n; i = j) {
					ll cur = 0;
					while (j < n && cur != target) cur += a[j++];
					if (cur != target) return false;
				}
				return true;
			}()) {
				cout << k << '\n';
				break;
			}
		}
	}
}