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

const int N = 1 << 10;
bool _vis[2 * N][2 * N];



struct point {
	int x, y;
	point(int a, int b) : x{a}, y{b} { }
	point operator+(point a) { return {x + a.x, y + a.y}; }
};
bool& vis(point p) { return _vis[p.x + N][p.y + N]; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	
	int res = 0;

	queue<pair<point, int>> q;
	if (n % 4 == 0) q.push({point(0, 0), 0});
	if (n % 4 == 1) {
		q.push({point(+1, 0), 0});
		q.push({point(0, +1), 0});
		q.push({point(-1, 0), 0});
		q.push({point(0, -1), 0});
	}
	if (n % 4 == 2) {
		q.push({point(+1, +1), 0});
		q.push({point(-1, +1), 0});
		q.push({point(+1, -1), 0});
		q.push({point(-1, -1), 0});
	}
	if (n % 4 == 3) {
		q.push({point(+1, +2), 0});
		q.push({point(-1, +2), 0});
		q.push({point(+1, -2), 0});
		q.push({point(-1, -2), 0});
		
		q.push({point(+2, +1), 0});
		q.push({point(-2, +1), 0});
		q.push({point(+2, -1), 0});
		q.push({point(-2, -1), 0});

		q.push({point(+1, 0), 0});
		q.push({point(0, +1), 0});
		q.push({point(-1, 0), 0});
		q.push({point(0, -1), 0});
	}

	n /= 4;

	vector<point> dir = {{-2, 0}, {+2, 0}, {0, -2}, {0, +2}, {+2, +2}, {-2, +2}, {+2, -2}, {-2, -2}};
	while (!q.empty()) {
		auto [p, d] = q.front(); q.pop();
		if (d > n || vis(p)) continue;
		++res;
		vis(p) = true;
		for (auto v : dir) q.push({p + v, d + 1});
	}

	cout << res << '\n';
}