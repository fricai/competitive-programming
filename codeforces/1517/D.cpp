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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 9;
const int inf = 1e9;

int n, m, k;
struct point {
	int x, y;
	point() { }
	point(int s) : x{s / m}, y{s % m} { }
	point(int a, int b) : x{a}, y{b} { }
	operator int() { return m * x + y; }
};
bool valid(point p) {
	return 0 <= p.x && p.x < n && 0 <= p.y && p.y < m;
}
point operator+(point a, point b) {
	return {a.x + b.x, a.y + b.y};
}

int dist(point a, point b) { return abs(a.x - b.x) + abs(a.y - b.y); }

const vector<point> dir = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};


const int K = 12;

int L[N][N], D[N][N];
int cost(point a, point b) {
	if (a.x == b.x) return L[a.x][max(a.y, b.y)];
	return D[max(a.x, b.x)][a.y];
}

int dp[N * N][K];
bool vis[N * N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	if (k & 1) {
		rep(i, 0, n) {
			rep(j, 0, m) cout << "-1 ";
			cout << '\n';
		}
		return 0;
	}

	rep(i, 0, n) rep(j, 1, m) cin >> L[i][j];
	rep(i, 1, n) rep(j, 0, m) cin >> D[i][j];

	k /= 2;
	for (int step = 1; step <= k; ++step) {
		rep(u, 0, n * m) {
			dp[u][step] = inf;
			for (auto d : dir) {
				point v = d + point(u);
				if (!valid(v)) continue;
				uin(dp[u][step], cost(u, v) + dp[v][step - 1]);
			}
		}
	}

	rep(i, 0, n) {
		rep(j, 0, m)
			cout << 2 * dp[point(i, j)][k] << ' ';
		cout << '\n';
	}
}