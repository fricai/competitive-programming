#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(int i) {
	cout << "? " << i + 1 << endl;
	int x; cin >> x;
	assert(x != 0);
	return x - 1;
}

void solve() {
	int n; cin >> n;

	vector<bool> vis(n);
	vector<int> p(n);

	rep(i, 0, n) {
		if (vis[i])
			continue;

		int init = ask(i);
		vector<int> cycle;
		do cycle.push_back(ask(i));
		while (cycle.back() != init);

		// p^(k + r)(i) = cycle[r]
		// p[cycle[i]] = cycle[i + 1]
		// p(cycle[r]) = cycle[r + 1]
		p[cycle.back()] = cycle.front();
		rep(i, 1, sz(cycle)) p[cycle[i - 1]] = cycle[i];

		for (auto x : cycle)
			vis[x] = true;
	}

	cout << "! ";
	for (auto x : p) cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) solve();
}
