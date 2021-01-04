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
int a[N], L[N], R[N], b[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		L[i] = i - 1;
		R[i] = i + 1;
	}

	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= n; ++i) pq.push({-a[i], i});

	ll ans = 0;
	int l = 1, r = n;
	while (sz(pq) > 2) {
		auto i = pq.top().second; pq.pop();
		if (i == l) { ans += a[i]; l = R[i]; continue; }
		if (i == r) { ans += a[i]; r = L[i]; continue; }
		// cerr << a[i] << '\n';
		ans += min(a[L[i]], a[R[i]]);
		R[L[i]] = R[i];
		L[R[i]] = L[i];
	}
	cout << ans;
}