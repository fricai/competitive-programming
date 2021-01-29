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

void solve() {
	int n; cin >> n;

	string s; cin >> s;
	
	vector<int> L(n + 1), R(n + 1);
	
	L[0] = 1;
	L[1] = 1 + (s[0] == 'L');
	for (int i = 2; i <= n; ++i) {
		if (s[i - 1] == 'L' && s[i - 2] == 'R') L[i] = 2 + L[i - 2];
		else if (s[i - 1] == 'L') L[i] = 2;
		else L[i] = 1;
	}

	R[n] = 1;
	R[n - 1] = 1 + (s[n - 1] == 'R');
	for (int i = n - 2; i >= 0; --i) {
		if (s[i] == 'R' && s[i + 1] == 'L') R[i] = 2 + R[i + 2];
		else if (s[i] == 'R') R[i] = 2;
		else R[i] = 1;
	}

	rep(i, 0, n + 1) cout << L[i] + R[i] - 1 << ' ';
	
	// rep(i, 0, n + 1) cerr << L[i] << ' ';
	// cerr << '\n';

	// rep(i, 0, n + 1) cerr << R[i] << ' ';
	// cerr << '\n';

	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}