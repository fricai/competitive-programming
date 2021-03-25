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
	vector<int> q(n);
	for (auto &x : q) cin >> x;
	
	vector<int> mn, mx;
	priority_queue<int> p_mx;
	priority_queue<int, vector<int>, greater<int>> p_mn;
	for (int i = 0, j = 0, pre = 0; i < n; i = j) {
		while (j < n && q[i] == q[j]) ++j;
		mn.push_back(q[i]);
		mx.push_back(q[i]);
		rep(j, pre + 1, q[i]) p_mn.push(j), p_mx.push(j);
		rep(k, i + 1, j) {
			mn.push_back(p_mn.top()); p_mn.pop();
			mx.push_back(p_mx.top()); p_mx.pop();
		}
		pre = q[i];
	}
	
	for (auto x : mn) cout << x << ' ';
	cout << '\n';
	for (auto x : mx) cout << x << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}