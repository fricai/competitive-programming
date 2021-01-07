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

const int N = 1 << 17, inf = 2e9;
int in[N], h[N];
int n; ll a, r, m;

ll f(ll t) {
	rep(i, 0, n) h[i] = in[i];

	ll s = 0;
	rep(i, 0, n) s += h[i];

	ll ans = 0;
	if (s < t * n) {
		ans += a * (t * n - s);
		rep(i, 0, n) {
			assert(h[i] < t);
			s += t - h[i];
			if (s >= t * n) {
				s -= t - h[i];
				h[i] += t * n - s;
				s = t * n;
				break;
			}
			h[i] = t;
		}
	} else if (s > t * n) {
		ans += r * (s - t * n);
		per(i, 0, n) {
			assert(t < h[i]);
			s -= h[i] - t;
			if (s <= t * n) {
				s += h[i] - t;
				h[i] += s - t * n;
				s = t * n;
				break;
			}
			h[i] = t;
		}
	}
	rep(i, 0, n) {
		if (h[i] > t) continue;
		ans += m * (t - h[i]);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> a >> r >> m;
	ckmin(m, a + r);
	rep(i, 0, n) cin >> in[i];
	sort(in, in + n);

	int l = 0, r = inf;
	while (r - l > 4) {
		int m = (l + r) / 2;
		if (f(m) > f(m + 1)) l = m;
		else r = m + 1;
	}

	ll ans = f(l);
	rep(i, l + 1, r + 1) ckmin(ans, f(i));
	cout << ans;
}