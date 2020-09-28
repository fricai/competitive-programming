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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 3e5 + 10, B = 30;
int t[B * N][2], a;
vector<int> pos[N * B];
int nc = 1;

int get(int v, bool b) {
	if (!t[v][b]) t[v][b] = ++nc;
	return t[v][b];	
}

void insert(int x, int i) {
	int v = 1;
	per(b, 0, B) {
		pos[v].push_back(i);
		v = get(v, x >> b & 1);
	}
	pos[v].push_back(i);
}

ll tot[B][2];
ll cnt(const vector<int> &a, const vector<int> &b) {
	ll inv = 0;
	for (int i = 0, j = 0; i < sz(a) && j < sz(b); ) {
		if (a[i] > b[j]) inv += sz(a) - i, ++j;
		else ++i;
	}
	return inv;
}

void dfs(int v, int bit) {
	if (bit < 0) return;
	rep(b, 0, 2) if (t[v][b]) dfs(t[v][b], bit - 1);
	if (!t[v][0] || !t[v][1]) return;
	tot[bit][0] += cnt(pos[t[v][0]], pos[t[v][1]]);
	tot[bit][1] += cnt(pos[t[v][1]], pos[t[v][0]]);	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a, insert(a, i);
	dfs(1, B - 1);
	ll inv = 0, x = 0;
	per(b, 0, B) {
		x <<= 1;
		if (tot[b][0] <= tot[b][1]) inv += tot[b][0];
		else x ^= 1, inv += tot[b][1];
	}
	cout << inv << ' ' << x << '\n';
}