#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18;
int a[N];

int solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	reverse(a, a + n);

	bool passed_peak = false;
	int cnt = n - 1;
	rep(i, 1, n) {
		if (!passed_peak) {
			if (a[i - 1] > a[i]) passed_peak = true;
		} else {
			if (a[i - 1] < a[i]) return cnt;
		}
		--cnt;
	}
	return cnt;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}