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

const int N = 5000 + 5, K = 5000 + 5;
bitset<K> s[N], p[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(all(a));
	while (!a.empty() && k <= a.back()) a.pop_back(), --n;

	// Find number of sets containing x whose sum is in [k, k + x)
	// If this is zero then no solution

	p[0] = 1; rep(i, 0, n) p[i + 1] = p[i] | p[i] << a[i];
	s[n] = 1; per(i, 0, n) s[i] = s[i + 1] | s[i + 1] << a[i];

	int ans = 0;
	rep(i, 0, n) {
		bool works = false;
		
		int cur = 0;
		rep(j, k - a[i] + 1, k + 1) cur += s[i + 1][j];
		rep(l, 0, k) {
			cur -= s[i + 1][k - l];
			if (0 <= k - a[i] - l) cur += s[i + 1][k - a[i] - l];
			works |= cur > 0 && p[i][l];
		}
		ans += !works;
	}
	cout << ans;
}