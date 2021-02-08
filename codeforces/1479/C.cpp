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

const int N = 22;
vector<tuple<int, int, int>> g;

void add_edge(int u, int v, int w) {
	g.emplace_back(u, v, w);
}

int f(int u) { return N + 1 - u; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int l, r; cin >> l >> r;

	int p = 1;
	for (int i = 2; i < N; ++i, p <<= 1) {
		add_edge(i, N, 1);
		rep(j, i + 1, N) add_edge(f(j), f(i), p);
	}
	
	add_edge(1, N, l);
	int T = r - l;
	per(i, 2, N) {
		p >>= 1;
		if (T & p) {
			T ^= p;
			add_edge(1, f(i), T + l);
		}
	}

	cout << "YES\n" << N << ' ' << sz(g) << '\n';
	for (auto [x, y, z] : g)
		cout << x << ' ' << y << ' ' << z << '\n';
}