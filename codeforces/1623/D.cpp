#include <bits/stdc++.h>

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

constexpr int mod = 1e9 + 7, i100 = 570000004;

int mul(ll x, int y) { return x * y % mod; }
int sub(int x, int y) { return x -= y, x < 0 ? x + mod : x; }
int add(int x, int y) { return x += y, x >= mod ? x - mod : x; }
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int bpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1)
			res = mul(res, a);
	return res;
}

int solve() {
	int n, m; cin >> n >> m;
	int s, t, a, b; cin >> s >> t >> a >> b; --s; --t; --a; --b;
	int p; cin >> p; p = mul(p, i100);

	int ex = 0, k = 0, prob = 1;
	int ds = 1, dt = 1;
	if (s + ds >= n || s + ds < 0) ds = -ds;
	if (t + dt >= m || t + dt < 0) dt = -dt;
	for (int x = s, y = t, dx = 1, dy = 1, pc = sub(1, p); ; x += dx, y += dy, ++k) {
		if (x + dx >= n || x + dx < 0) dx = -dx;
		if (y + dy >= m || y + dy < 0) dy = -dy;
		if (k > 0 && x == s && y == t && dx == ds && dy == dt)
			break;
		if (x == a || y == b) {
			inc(ex, mul(mul(p, prob), k));
			prob = mul(prob, pc);
		}
	}
	return mul(ex + mul(prob, k), bpow(sub(1, prob), mod - 2));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
