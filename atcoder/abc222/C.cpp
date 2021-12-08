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

constexpr int s[3][3] = {{0, +1, 0}, {0, 0, +1}, {+1, 0, 0}};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<char, int> mp = {{'G', 0}, {'C', 1}, {'P', 2}};

	int n, m; cin >> n >> m;

	vector<int> ord(n + n), sc(n + n);
	iota(all(ord), 0);

	vector a(n + n, vector(m, 0));
	for (auto &v : a) {
		string s; cin >> s;
		rep(i, 0, m) v[i] = mp[s[i]];
	}

	rep(j, 0, m) {
		sort(all(ord), [&](int x, int y) {
				return pair(sc[x], -x) > pair(sc[y], -y);
				});

		rep(i, 0, n) {
			int u = ord[i << 1], v = ord[i << 1|1];
			sc[v] += s[a[v][j]][a[u][j]];
			sc[u] += s[a[u][j]][a[v][j]];
		}
	}

	sort(all(ord), [&](int x, int y) {
			return pair(sc[x], -x) > pair(sc[y], -y);
			});

	for (auto x : ord)
		cout << x + 1 << '\n';
}
