#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define eb(x...) emplace_back(x)

using pii = pair<int, int>;
using ll = int64_t;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll u, v; cin >> u >> v;
	if (u == v && v == 0) return cout << 0, 0;
	if (u > v || u % 2 != v % 2) return cout << -1, 0;
	if (u == v) return cout << 1 << '\n' << u << '\n', 0;
	ll d = (v - u) / 2;
	if (((u + d) ^ d) == u)
		return cout << 2 << '\n' << u + d << ' ' << d << '\n', 0;
	cout << 3 << '\n' << u << ' ' << d << ' ' << d << '\n';
}