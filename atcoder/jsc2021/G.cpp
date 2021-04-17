#include <atcoder/modint>
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

const int N = 300 + 2, M = 1e9 + 7;
using mint = atcoder::static_modint<M>;

mint det(vector<vector<mint>>& a) {
	int n = sz(a);

	mint res = 1;
	rep(i, 0, n) {
		if (a[i][i] == 0) return 0;
		res *= a[i][i];
		auto x = 1 / a[i][i];
		rep(j, i + 1, n) {
			mint v = a[j][i] * x;
			rep(k, i + 1, n) a[j][k] -= v * a[i][k];
		}
	}
	return res;
}

int a[N][N];
int cc[N];
int cnt = 0;
int n;

bool cycle(int u, int p) {
	cc[u] = cnt;
	rep(v, 0, n) {
		if (v == p || a[u][v] != 1) continue;
		if (cc[v] || cycle(v, u)) return 1;
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
	rep(u, 0, n)
		if (!cc[u]) {
			++cnt;
			if (cycle(u, -1)) return cout << "0\n", 0;
		}
	rep(u, 0, n) --cc[u];

	vector<vector<mint>> L(cnt, vector<mint>(cnt, 0));

	rep(u, 0, n) {
		rep(v, 0, n) {
			if (a[u][v] != -1) continue;
			--L[cc[u]][cc[v]];
			++L[cc[u]][cc[u]];
		}
	}

	L.pop_back();
	for (auto &b : L) b.pop_back();

	cout << det(L).val() << '\n';
}