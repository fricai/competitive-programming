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

constexpr int n = 9, t = 362880;
array<vector<int>, t> h;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m; cin >> m;
	array<vector<int>, n> g;
	rep(e, 0, m) {
		int u, v; cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	array<int, n - 1> p;
	for (auto &x : p)
		cin >> x, --x;

	array<int, n> s;
	iota(all(s), 0);

	map<array<int, n>, int> mp;
	int counter = 0;
	do mp[s] = counter++;
	while (next_permutation(all(s)));

	do {
		int cur = mp[s];
		int u = find(all(s), n - 1) - begin(s);
		for (auto v : g[u]) {
			swap(s[u], s[v]);
			h[cur].push_back(mp[s]);
			swap(s[u], s[v]);
		}
	} while (next_permutation(all(s)));


	array<int, n> start;
	fill(all(start), n - 1);
	rep(i, 0, n - 1) start[p[i]] = i;

	queue<int> q ;
	array<int, t> d;
	fill(all(d), t);

	int st = mp[start];
	d[st] = 0;
	q.push(st);

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : h[u]) {
			if (d[v] < t)
				continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}

	cout << (d[0] < t ? d[0] : -1) << '\n';
}
