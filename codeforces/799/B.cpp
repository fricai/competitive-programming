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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> p(n), a(n), b(n);
	for (auto &x : p) cin >> x;
	for (auto &x : a) cin >> x, --x;
	for (auto &x : b) cin >> x, --x;

	vector<int> s[3];
	rep(i, 0, n) {
		s[a[i]].push_back(i);
		if (a[i] != b[i])
			s[b[i]].push_back(i);
	}
	rep(b, 0, 3)
		sort(all(s[b]), [&](int x, int y) {
			return p[x] > p[y];
		});

	vector<bool> dead(n);
	int m; cin >> m;
	rep(i, 0, m) {
		int c; cin >> c; --c;
		while (!s[c].empty() && dead[s[c].back()])
			s[c].pop_back();
		if (s[c].empty())
			cout << "-1 ";
		else {
			int j = s[c].back();
			cout << p[j] << ' ';
			dead[j] = 1;
		}
	}
	cout << '\n';
}