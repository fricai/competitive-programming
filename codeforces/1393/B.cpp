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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 17;
int f[N];
set<int> cnt[10];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) {
		int a; cin >> a;
		++f[a];
	}

	rep(x, 0, N) cnt[min(f[x], 8)].insert(x);

	int q; cin >> q;

	auto solve = [&]() {
		if (sz(cnt[8]) >= 1) return true;

		int x = 0;
		rep(i, 4, 9) x += sz(cnt[i]);
		if (x >= 2) return true;

		if (x >= 1) {
			int z = -1;
			rep(i, 4, 9) {
				if (sz(cnt[i]) >= 1) {
					z = *begin(cnt[i]);
					cnt[i].erase(z);
					cnt[i - 4].insert(z);
					break;
				}
			}

			assert(z > 0);
			int r = 0;
			rep(i, 2, 9) r += sz(cnt[i]);
			cnt[f[z] - 4].erase(z);
			cnt[f[z]].insert(z);
			if (r >= 2) return true;
			return false;
		}
		return false;
	};

	while (q--) {
		char c; cin >> c;
		int x; cin >> x;

		cnt[min(8, f[x])].erase(x);
		if (c == '+') cnt[min(++f[x], 8)].insert(x);
		else cnt[min(--f[x], 8)].insert(x);
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}