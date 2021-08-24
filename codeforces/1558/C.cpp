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

void answer() { cout << "-1\n"; }
void answer(vector<int> v) {
	cout << sz(v) << '\n';
	for (auto x : v)
		cout << x + 1 << ' ';
	cout << '\n';
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x, --x;

	rep(i, 0, n)
		if ((i ^ a[i]) & 1)
			return answer();

	vector<int> ops;
	auto do_op = [&](int p) {
		assert(~p & 1);
		for (int i = 0; i < p - i; ++i)
			swap(a[i], a[p - i]);
		ops.emplace_back(p);
	};

	auto locate = [&](int x) {
		return find(all(a), x) - begin(a);
	};

	for (;n > 1; n -= 2) {
		do_op(locate(n - 1));
		do_op(locate(n - 2) - 1);
		do_op(n - 1);
		do_op(locate(n - 1));
		do_op(n - 1);
	}
	assert(is_sorted(all(a)));

	answer(ops);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
	int n; cin >> n;
	vector<int> root(n);
	for (auto &x : root)
		cin >> x;

	map<vector<int>, int> hsh;

	vector<int> v(n);
	iota(all(v), 0);
	int cnt = 0;
	do hsh[v] = cnt++;
	while (next_permutation(all(v)));

	queue<vector<int>> q;
	q.push(root);

	vector<bool> vis(cnt);
	vis[hsh[root]] = true;

	vector<vector<int>> par(cnt);

	vector<int> fin;
	while (!q.empty()) {
		auto v = q.front(); q.pop();
		rep(i, 1, n)
			if (v[i] == n - 2 && v[i - 1] == n - 1) {
				fin = v;
				break;
			}
		if (!fin.empty())
			break;

		for (int p = 2; p < n; p += 2) {
			vector<int> u(n);
			for (int i = 0; i <= p; ++i)
				u[i] = v[p - i];
			for (int i = p + 1; i < n; ++i)
				u[i] = v[i];
			int r = hsh[u];
			if (!vis[r]) {
				vis[r] = true;
				par[r] = v;
				q.push(u);
			}
		}
	}

	for (auto x : fin)
		cout << x << ' ';
	cout << '\n';
	while (fin != root) {	
		fin = par[hsh[fin]];
		for (auto x : fin)
			cout << x << ' ';
		cout << '\n';
	}
	*/

	int t; cin >> t;
	while (t--) solve();
}
