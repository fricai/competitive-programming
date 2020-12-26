#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 9;
char _g[N][N];

struct point {
	int x, y;
	point() { }
	point(int x, int y) : x{x}, y{y} { }
	point operator+(point a) { return {x + a.x, y + a.y}; }
};

bool _vis[N][N];
char& g(point p) { return _g[p.x][p.y]; }
bool& vis(point p) { return _vis[p.x][p.y]; }

int n, m;
bool valid(point p) { return 0 <= p.x && p.x < n && 0 <= p.y && p.y < m; }

const vector<point> dir = {{-1, 0}, {+1, 0}, {0, +1}, {0, -1}};

vector<pair<char, point>> op;
void dfs(point u) {
	vis(u) = true;
	op.emplace_back('B', u);
	for (auto d : dir) {
		auto v = u + d;
		if (!valid(v) || vis(v)) continue;
		dfs(v);
	}
	op.emplace_back('D', u);
	op.emplace_back('R', u);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	rep(i, 0, n) cin >> _g[i];

	rep(i, 0, n) rep(j, 0, m) {
		auto v = point(i, j);
		vis(v) = g(v) != '.';
	}
	rep(i, 0, n) rep(j, 0, m)
		if (!vis(point(i, j))) {
			dfs(point(i, j));
			op.pop_back();
			op.pop_back();
		}

	cout << sz(op) << '\n';
	for (auto [c, p] : op) cout << c << ' ' << p.x + 1 << ' ' << p.y + 1 << '\n';
}