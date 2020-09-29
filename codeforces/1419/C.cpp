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

const int N = 1 << 10;
int a[N];

int solve() {
	int n, x; cin >> n >> x;
	rep(i, 0, n) cin >> a[i];

	bool alleq = true;
	rep(i, 0, n) if (a[i] != x) alleq = false;
	if (alleq) return 0;
	rep(i, 0, n) if (a[i] == x) return 1;
	ll sum = 0;
	rep(i, 0, n) sum += a[i] - x;
	if (!sum) return 1;
	return 2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}