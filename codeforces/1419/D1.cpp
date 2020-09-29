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
int a[N], b[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	sort(a, a + n);
	int j = n - 1;
	for (int i = 0; i < n; i += 2, --j) b[i] = a[j];
	for (int i = 1; i < n; i += 2, --j) b[i] = a[j];
	int cnt = 0;
	rep(i, 1, n - 1) if (b[i - 1] > b[i] && b[i] < b[i + 1]) ++cnt;
	cout << cnt << '\n';
	rep(i, 0, n) cout << b[i] << ' ';
	cout << '\n';
}