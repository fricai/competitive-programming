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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<class T>
using ost = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

const int M = 998244353;
int mul(ll x, int y) { return x * y % M; }
int bpow(int a, ll b) {
	int res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1)
			res = mul(res, a);
	return res;
}

const int N = 1 << 18;
int f[N << 1], fi[N << 1];

int C(int n, int r) {
	if (r < 0 || r > n)
		return 0;
	return mul(f[n], mul(fi[r], fi[n - r]));
}

bool taken[N];
ost<int> alive;
int solve() {
	int n, m; cin >> n >> m;

	vector<pair<int, int>> v(m);
	for (auto &[x, y] : v)
		cin >> x >> y;
	reverse(all(v));

	vector<int> marked;
	vector<int> dead;
	int del = 0;
	for (auto [x, y] : v) {
		auto p = alive.find_by_order(y - 1);
		auto q = *alive.find_by_order(y);
		dead.push_back(*p);
		alive.erase(p);
		if (!taken[q]) {
			taken[q] = true;
			marked.push_back(q);
			++del;
		}
	}
	for (auto x : marked)
		taken[x] = false;
	for (auto x : dead)
		alive.insert(x);
	return C(2 * n - del - 1, n);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = 1;
	rep(i, 1, N << 1) f[i] = mul(i, f[i - 1]);
	fi[2 * N - 1] = bpow(f[2 * N - 1], M - 2);
	per(i, 1, N << 1) fi[i - 1] = mul(i, fi[i]);

	rep(i, 0, N) alive.insert(i);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
