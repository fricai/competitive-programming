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
int a[N], n;
vector<int> b;

void construct(int x) {
	int u = 0, v = n - x - 1;
	b.clear();
	rep(i, 0, 2 * x + 1) {
		if (i & 1) b.eb(a[u++]);
		else b.eb(a[v++]);
	}
	while (sz(b) != n) b.eb(a[u++]);
}

bool check(int x) {
	if (2 * x + 1 > n) return 0;
	construct(x);
	int cnt = 0;
	rep(i, 1, n - 1) if (b[i - 1] > b[i] && b[i] < b[i + 1]) ++cnt;
	return cnt >= x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	sort(a, a + n);
	int l = 0, r = n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		(check(m) ? l : r) = m;
	}
	
	construct(l);
	cout << l << '\n';
	rep(i, 0, n) cout << b[i] << ' ';
}