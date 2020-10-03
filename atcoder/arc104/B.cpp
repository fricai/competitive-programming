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

const int N = 1 << 15;
int A[N], C[N], G[N], T[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	string s; cin >> s;
	for (int i = 1; i <= n; ++i) {
		char c = s[i - 1];
		A[i] = A[i - 1];
		C[i] = C[i - 1];
		T[i] = T[i - 1];
		G[i] = G[i - 1];
		if (c == 'A') ++A[i];
		if (c == 'C') ++C[i];
		if (c == 'T') ++T[i];
		if (c == 'G') ++G[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (A[j] - A[i] == T[j] - T[i] && C[j] - C[i] == G[j] - G[i])
				++ans;
				
	cout << ans;
}