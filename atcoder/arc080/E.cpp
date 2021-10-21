#include <bits/stdc++.h>
#include <atcoder/segtree>

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


constexpr int inf = 1e9;
template<class T> T op(T a, T b) { return min(a, b); }
pair<int, int> e() { return {inf, inf}; }

template<class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> p(n), loc(n);
	for (auto &x : p)
		cin >> x, --x;
	rep(i, 0, n) loc[p[i]] = i;

	atcoder::segtree<pair<int, int>, op, e> t[2];
	t[0] = atcoder::segtree<pair<int, int>, op, e>(n);
	t[1] = atcoder::segtree<pair<int, int>, op, e>(n);
	rep(i, 0, n) {
		t[i & 1].set(i, {p[i], i});
	}

	vector<int> q;
	minpq<tuple<int, int, int>> pq;

	auto add = [&](int l, int r) {
		if (l == r)
			return;
		pq.push({t[l & 1].prod(l, r).first, l, r});
	};

	add(0, n);
	while (!pq.empty()) {
		auto [x, l, r] = pq.top(); pq.pop();
		int i = loc[x];
		auto [y, j] = t[~i & 1].prod(i, r);
		assert(y != inf);
		add(l, i);
		add(i + 1, j);
		add(j + 1, r);
		q.push_back(x);
		q.push_back(y);
	}

	for (auto x : q)
		cout << x + 1 << ' ';
	cout << '\n';
}
