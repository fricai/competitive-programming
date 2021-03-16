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

const int B = 10, N = 1 << B, inf = 1e9 + 20;
int ans[N];

int n;
vector<int> ask(vector<int> v) {
	if (v.empty()) return vector<int>(n, inf);
	cout << sz(v) << endl;
	for (auto x : v) cout << x << ' ';
	cout << endl;
	vector<int> res(n);
	for (auto &x : res) cin >> x;
	return res;
}

vector<int> a[2], r[2];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) ans[i] = inf;
	rep(b, 0, B) {
		rep(c, 0, 2) a[c].clear();
		for (int i = 1; i <= n; ++i)
			a[i >> b & 1].push_back(i);
		rep(c, 0, 2) r[c] = ask(a[c]);
		for (int i = 1; i <= n; ++i)
			ckmin(ans[i], r[~i >> b & 1][i - 1]);
	}

	cout << "-1" << endl;
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	cout << endl;
}