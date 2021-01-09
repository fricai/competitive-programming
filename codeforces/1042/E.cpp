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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int NM = 1 << 20, M = 998244353;
int E[NM];

template<class S, class T> void add(S& x, T y) { x += y; if (M <= x) x -= M; }
template<class S, class T> void sub(S& x, T y) { x -= y; if (x < 0) x += M; }

using ull = unsigned long long;
ull modmul(ull a, ull b) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

int inv[NM];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inv[1] = 1;
	rep(i, 2, NM) inv[i] = M - modmul(M / i, inv[M % i]);

	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> chips;
	rep(i, 0, n) {
		rep(j, 0, m) {
			int x; cin >> x;
			chips.emplace_back(x, i, j);
		}
	}
	int r, c; cin >> r >> c; --r; --c;

	/*
		Let S(u) = {v | a[v] < a[u]}
		E[v] = (sum (i(v) - i(u))^2 + (j(v) - j(u))^2 + E[v]) / S(u)
			= (sum i(v)^2 + j(v)^2 + i(u)^2 + j(u)^2 - 2 * i(u) * i(v) - 2 * j(u) * j(v) + E[v]) / S(u)
			= (sum i(v)^2 + j(v)^2 + E[v]) / S(u)
			 	- 2 i(u) * (sum i(v)) / S(u)
				- 2 j(u) * (sum j(v)) / S(u)
				+ i(u)^2 + j(u)^2
	*/
	sort(all(chips));

	int sum = 0, i_sum = 0, j_sum = 0, cnt = 0;
	for (int i = 0, j = 0; i < n * m; i = j) {
		while (j < n * m && get<0>(chips[i]) == get<0>(chips[j])) ++j;

		rep(k, i, j) {
			if (cnt) {
				auto [_, x, y] = chips[k];

				E[k] = sum;
				sub(E[k], modmul(2 * x, i_sum));
				sub(E[k], modmul(2 * y, j_sum));

				E[k] = modmul(E[k], inv[cnt]);

				add(E[k], modmul(x, x));
				add(E[k], modmul(y, y));
			}
		}

		rep(k, i, j) {
			auto [_, x, y] = chips[k];
			if (x == r && y == c) cout << E[k];
			add(sum, E[k]);
			add(sum, modmul(x, x));
			add(sum, modmul(y, y));

			add(i_sum, x);
			add(j_sum, y);
			++cnt;
		}
	}
}