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

const int N = 1 << 10;
int r[N], c[N], inv_r[N], inv_c[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> r[i], inv_r[r[i]] = i;
	for (int i = 1; i <= n; ++i) cin >> c[i], inv_c[c[i]] = i;
	
	vector<array<int, 4>> res;
	for (int i = 1; i < n; ++i) {
		if (r[i] == i && c[i] == i) continue;
		res.push_back({inv_r[i], i, i, inv_c[i]});

		int x, y;
		tie(x, y) = {r[i], inv_r[i]};
		tie(r[i], inv_r[i]) = {r[y], inv_r[x]};
		tie(r[y], inv_r[x]) = {x, y};
		
		tie(x, y) = {c[i], inv_c[i]};
		tie(c[i], inv_c[i]) = {c[y], inv_c[x]};
		tie(c[y], inv_c[x]) = {x, y};
	}

	cout << sz(res) << '\n';
	for (auto &z : res) {
		for (auto x : z)
			cout << x << ' ';
		cout << '\n';
	}
	cout << '\n';
}