// solution for substring

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int A = 26;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a; cin >> a;

	int n = sz(a);

	vector nxt(n + 1, vector(A, n));
	per(i, 0, n) {
		nxt[i] = nxt[i + 1];
		nxt[i][a[i] - 'a'] = i;
	}

	/*
	rep(i, 0, n) {
		for (auto x : nxt[i])
			cerr << x << ' ';
		cerr << '\n';
	}
	*/

	
	vector<int> dp(n + 2);
	dp[n + 1] = 0;
	dp[n] = n;
	per(i, 0, n) {
		dp[i] = n;
		rep(c, 0, A) {
			uin(dp[i], dp[nxt[i][c] + 1] + 1);
		}
	}

	cerr << dp[0] << '\n';

	for (int i = 0; i < n; ) {
		for (int c = 0; c < A; ++c) {
			if (dp[i] == dp[nxt[i][c] + 1] + 1) {
				cout << char(c + 'a');
				i = nxt[i][c] + 1;
				break;
			}
		}
	}
}
