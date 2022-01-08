#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using i128 = __int128_t;

constexpr int N = 20;
i128 p[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	rep(i, 1, N) p[i] = 10 * p[i - 1];

	ll x; cin >> x;
	i128 res = p[N - 1];
	rep(a, 0, 10) {
		rep(d, -10, 10) {
			rep(n, 1, N) {
				i128 cur = 0;
				rep(i, 0, n) {
					if (a + i * d < 0 || a + i * d > 9) {
						cur = -1;
						break;
					}
					cur += (a + i * d) * p[i];
				}

				if (cur >= x) uin(res, cur);
			}
		}
	}
	cout << ll(res) << '\n';
}
