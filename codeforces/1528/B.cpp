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

const int N = 1 << 20, M = 119 << 23 | 1;
int f[N];

void add(int &x, int y) { x += y; if (M <= x) x -= M; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		for (int x = i; x <= n; x += i)
			++f[x];
		add(f[i], cur);
		add(cur, f[i]);
	}

	cout << f[n] << '\n';
}