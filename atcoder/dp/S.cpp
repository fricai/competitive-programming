#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define ff first
#define ss second

using ll = int64_t;

const int M = 1e9 + 7;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using vi = vector<int>;
using vvi = vector<vi>;

template<class T>
void add(T& a, const T& b) {
	a += b;
	if (a >= M) a -= M;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string k; int d; cin >> k >> d;
	vvi f(d, vi(2)); f[0][0] = 1;
	rep(i, 0, sz(k)) {
		vvi g(d, vi(2));
		rep(x, 0, d) {
			rep(c, 0, 10) add(g[(x + c) % d][1], f[x][1]);
			rep(c, 0, k[i] - '0') add(g[(x + c) % d][1], f[x][0]);
			add(g[(x + k[i] - '0') % d][0], f[x][0]);
		}
		swap(f, g);
	}
	cout << (f[0][0] + f[0][1] + M - 1) % M;
}