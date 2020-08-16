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

const int N = 1 << 18;
char a[N];
int nxt[N], pre[N];

int solve() {
	int n; cin >> n >> a;
	bool ok = false;
	rep(i, 1, n) if (a[i] != a[i - 1]) ok = true;
	if (!ok) return (n + 2) / 3;
	if (a[n - 1] == 'R') {
		int i = n - 1;
		while (a[i] == 'R') --i;
		rotate(a, a + i + 1, a + n);
	}
	if (a[0] == 'L') {
		int i = 0;
		while (a[i] == 'L') ++i;
		rotate(a, a + i, a + n);
	}

	assert(a[0] != 'L' && a[n - 1] != 'R');

	int res = 0;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && a[i] == a[j]) ++j;
		res += max(0, (j - i) / 3);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}