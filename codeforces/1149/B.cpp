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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int A = 26;
const int X = 1 << 8;
int dp[X][X][X];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	string s; cin >> s;
	
	vector nxt(n + 2, vector(A, n));
	per(i, 0, n) {
		nxt[i] = nxt[i + 1];
		nxt[i][s[i] - 'a'] = i;
	}
	
	string t[3];
	dp[0][0][0] = -1;
	auto recompute = [&](int a, int b, int c) {
		dp[a][b][c] = n;
		if (a) uin(dp[a][b][c], nxt[dp[a - 1][b][c] + 1][t[0][a - 1] - 'a']);
		if (b) uin(dp[a][b][c], nxt[dp[a][b - 1][c] + 1][t[1][b - 1] - 'a']);
		if (c) uin(dp[a][b][c], nxt[dp[a][b][c - 1] + 1][t[2][c - 1] - 'a']);
	};
	
	while (q--) {
		char type; cin >> type;
		if (type == '+') {			
			int i; char c; cin >> i >> c; --i;

			t[i].push_back(c);

			int la = 0, lb = 0, lc = 0;
			
			if (i == 0) la = sz(t[0]);
			if (i == 1) lb = sz(t[1]);
			if (i == 2) lc = sz(t[2]);

			for (int a = la; a <= sz(t[0]); ++a)
				for (int b = lb; b <= sz(t[1]); ++b)
					for (int c = lc; c <= sz(t[2]); ++c)
						recompute(a, b, c);
		} else {
			int i; cin >> i; --i;
			t[i].pop_back();
		}

		cout << (dp[sz(t[0])][sz(t[1])][sz(t[2])] < n ? "YES" : "NO") << '\n';
	}
}