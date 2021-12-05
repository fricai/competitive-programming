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

template<class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

constexpr ll inf = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> s(n), t(n);
	for (auto &x : s) cin >> x;
	for (auto &x : t) cin >> x;

	minpq<pair<ll, int>> q;
	rep(i, 0, n) q.push({t[i], i});

	vector<ll> ans(n, inf);
	while (!q.empty()) {
		auto [t, i] = q.top();
		q.pop();
		if (uin(ans[i], t)) {
			q.push({t + s[i], (i + 1) % n});
		}
	}
	for (auto x : ans)
		cout << x << '\n';
}
