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

const ll inf = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(3 * n);
	for (auto &x : a) cin >> x;

	priority_queue<int> q;

	vector<ll> f(n + 1), s(n + 1);

	rep(i, 0, n) q.push(-a[i]), f[0] += a[i];
	rep(i, 0, n) {
		f[i + 1] = f[i] + a[i + n];
		q.push(-a[i + n]);
		f[i + 1] += q.top();
		q.pop();
	}
	
	// rep(i, 0, n + 1) cerr << f[i] << ' ';
	// cerr << '\n';

	q = { };
	rep(i, 2 * n, 3 * n) q.push(a[i]), s[n] += a[i];
	per(i, 0, n) {
		s[i] = s[i + 1] + a[i + n];
		q.push(a[i + n]);
		s[i] -= q.top();
		q.pop();
	}

	// rep(i, 0, n + 1) cerr << s[i] << ' ';
	// cerr << '\n';

	ll res = -inf;
	rep(i, 0, n + 1) ckmax(res, f[i] - s[i]);
	cout << res;
}