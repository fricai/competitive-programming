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

bool solve() {
	int n; cin >> n;
	vector<int> l(n), r(n);
	rep(i, 0, n) cin >> l[i] >> r[i];
	map<int, minpq<pair<int, int>>> mp;
	rep(i, 0, n) mp[l[i]].push({r[i], i});

	for (auto &[l, q] : mp) {
		if (q.empty())
			continue;
		auto [r, i] = q.top();
		if (r < l)
			return false;
		q.pop();
		auto &s = mp[l + 1];
		if (sz(s) < sz(q))
			swap(s, q);
		while (!q.empty()) {
			s.push(q.top());
			q.pop();
		}
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "Yes" : "No") << '\n';
}
