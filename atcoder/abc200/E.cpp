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
int cnt2[3 * N];
ll cnt[3 * N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// cnt2[z] = numner of solutios to i + j
	int n; ll k; cin >> n >> k;

	for (int r = 1; r <= 3 * n; ++r)
		cnt2[r] = max(0, min(n, r - 1) - max(1, r - n) + 1);
	
	for (int r = 1; r <= 3 * n; ++r) {
		cnt[r] = cnt[r - 1] + cnt2[r - 1];
		if (r - n - 1 >= 0) cnt[r] -= cnt2[r - n - 1];
	}
	
	int s = 0;
	while (k > 0) k -= cnt[++s];
	k += cnt[s];

	// sum decide
	// now fix i
	int i = 0;
	while (i < n && k > 0) k -= cnt2[s - ++i];
	k += cnt2[s - i];

	int j = 0;
	while (k > 0) {
		// if there is a solution start with i, j which sums to k
		++j;
		int l = s - (i + j);
		k -= 1 <= l && l <= n;
	}
	
	cout << i << ' ' << j << ' ' << s - i - j << '\n';
}