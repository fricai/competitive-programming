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

const int N = 3e5 + 10, B = 150;

vector<int> p[N];

int n, a[N];
int f[N][B], c[N][B], l[N], r[N], k[N], ord[N], s[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> n >> q;
	rep(i, 0, n) {
		cin >> a[i];
		p[a[i]].push_back(i);
	}

	rep(i, 0, q) {
		cin >> l[i] >> r[i] >> k[i]; --l[i];
		uniform_int_distribution dis(l[i], r[i] - 1);
		rep(j, 0, B) f[i][j] = a[dis(rng)];
		ord[i] = i;
	}
	sort(ord, ord + q, [&](int x, int y) { return l[x] < l[y]; });

	rep(i, 0, q) {
		rep(j, 0, B) {
			int x = f[ord[i]][j];
			while (s[x] < sz(p[x]) && p[x][s[x]] < l[ord[i]]) ++s[x];
			c[ord[i]][j] = -s[x];
		}
	}
	sort(ord, ord + q, [&](int x, int y) { return r[x] < r[y]; });
	
	for (int x = 1; x <= n; ++x) s[x] = 0;
	rep(i, 0, q) {
		rep(j, 0, B) {
			int x = f[ord[i]][j];
			while (s[x] < sz(p[x]) && p[x][s[x]] < r[ord[i]]) ++s[x];
			c[ord[i]][j] += s[x];
		}
	}
	rep(i, 0, q) {
		int ans = n + 1;
		rep(j, 0, B) if (k[i] * c[i][j] > r[i] - l[i]) ckmin(ans, f[i][j]);
		cout << (ans <= n ? ans : -1) << '\n';
	}
}