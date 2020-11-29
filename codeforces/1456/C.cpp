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

const int N = 1 << 19;
int c[N];

ll solve() {
	int n, k; cin >> n >> k;
	rep(i, 0, n) cin >> c[i];
	priority_queue<ll> q;
	for (int i = 0; i <= k; ++i) q.push(0);
	sort(c, c + n, greater<>());
	ll S = 0;
	rep(i, 0, n) {
		ll x = q.top(); q.pop();
		S += x; x += c[i];
		q.push(x);
	}
	return S;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solve() << '\n';
}