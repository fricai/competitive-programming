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

const int N = 1 << 17, M = 1 << 7;
int a[N];
int p[M][M], s[M][M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(i, 1, n) {
		int x = a[i] ^ a[i - 1];
		if ((i > 1 && a[i - 2] > x) || (i + 1 < n && x > a[i + 1])) return cout << "1\n", 0;
	}
	assert(n <= 60);
	
	rep(i, 0, n) {
		p[i][0] = s[i][0] = a[i];
		for (int j = 1; i + j < n; ++j)
			p[i][j] = p[i][j - 1] ^ a[i + j];
		for (int j = 1; j <= i; ++j)
			s[i][j] = s[i][j - 1] ^ a[i - j];
	}
	
	int ans = N;
	rep(i, 1, n)
		for (int j = 0; i + j < n; ++j)
			for (int k = 0; k < i; ++k)
				if (s[i - 1][k] > p[i][j])
					ckmin(ans, j + k);
	cout << (ans < N ? ans : -1);
}