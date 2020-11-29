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

const int N = 1 << 6;
int a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	if (N <= n) return cout << "1\n", 0;

	rep(i, 0, n) cin >> a[i];	
	int ans = N;
	rep(i, 1, n)
		for (int j = 0, r = a[i]; i + j < n; ++j, r ^= a[i + j])
			for (int k = 0, l = a[i - 1]; k < i; ++k, l ^= a[i - k - 1])
				if (l > r) ckmin(ans, j + k);
	cout << (ans < N ? ans : -1);
}