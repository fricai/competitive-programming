#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 10;
vector<int> p[N], bridge[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) {
		int k; cin >> k;
		rep(j, 0, k) {
			int q; cin >> q;
			p[i].eb(q); p[(i + 1) % n].eb(q);
			bridge[i].eb(q);
		}
	}

	rep(i, 0, n) {
		sort(all(p[i]));
		sort(all(bridge[i]));
	}

	int ans = 0;
	rep(i, 0, n) {
		rep(j, 0, sz(bridge[i]) - 1) {
			int left = lb(all(p[i]), bridge[i][j + 1]) - lb(all(p[i]), bridge[i][j]);
			int right = lb(all(p[(i + 1) % n]), bridge[i][j + 1]) - lb(all(p[(i + 1) % n]), bridge[i][j]);
			if (left != right) ++ans;
		}
	}
	cout << ans;
}