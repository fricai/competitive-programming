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

const int N = 1 << 20;
int p[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k; cin >> n >> k;
	ll L = n * (n + 1) / 2, R = 0;
	for (int a = n, b = 1; b <= n; --a, ++b)
		R += max(a, b);
	for (int i = 1; i <= n; ++i) p[i] = i;
	k = min(R, k);
	
	if (k < L) return cout << "-1\n", 0;

	for (ll l = 1, r = n, del = k - L; del != 0; ) {
		if (del > r - l) {
			swap(p[l], p[r]);
			del -= r - l;
			++l; --r;
		} else {
			swap(p[l], p[l + del]);
			del = 0;
		}
	}

	cout << k << '\n';
	for (int i = 1; i <= n; ++i) cout << i << ' ';
	cout << '\n';
	for (int i = 1; i <= n; ++i) cout << p[i] << ' ';
	cout << '\n';
}