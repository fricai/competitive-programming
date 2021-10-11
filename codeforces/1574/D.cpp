#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void print(vector<int> ans) {
	for (auto x : ans)
		cout << x + 1 << ' ';
	cout << '\n';
	exit(0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<int>> a(n);

	vector<int> best;
	for (auto &v : a) {
		int c; cin >> c;
		v.resize(c);
		for (auto &x : v)
			cin >> x;
		best.push_back(c - 1);
	}

	int m; cin >> m;
	set<vector<int>> banned;
	rep(e, 0, m) {
		vector<int> b(n);
		for (auto &x : b)
			cin >> x, --x;
		banned.insert(b);
	}

	if (!banned.count(best))
		print(best);

	ll mx = -1;
	for (auto v : banned) {
		ll cur = 0;
		rep(i, 0, n) cur += a[i][v[i]];
		rep(i, 0, n) {
			if (v[i] == 0)
				continue;
			cur -= a[i][v[i]];
			--v[i];
			cur += a[i][v[i]];
			if (cur > mx && !banned.count(v)) {
				mx = cur;
				best = v;
			}
			cur -= a[i][v[i]];
			++v[i];
			cur += a[i][v[i]];
		}
	}

	print(best);
}
