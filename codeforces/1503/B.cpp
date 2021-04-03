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

const int N = 1 << 7;

int g[N][N];
int n;

bool valid(int i, int j) { return 1 <= i && i <= n && 1 <= j && j <= n; }

int blocked() { int x; cin >> x; return x; }
void print(int b, int i, int j) {
	assert(valid(i, j));
	assert(g[i][j] == 0);
	g[i][j] = b;
	cout << b << ' ' << i << ' ' << j << endl;

	// cerr << '\n';
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = 1; j <= n; ++j) {
	// 		cerr << g[i][j] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
}

bool blocker(int i, int j) { return valid(i, j) && g[i][j] != 0; }
bool eh(int i, int j, int b) {
	return blocker(i, j) && g[i][j] != b;
}

bool soft_spot(int i, int j, int b) {
	if (g[i][j]) return 0;

	if (blocker(i - 1, j) && g[i - 1][j] == b) return 0;
	if (blocker(i + 1, j) && g[i + 1][j] == b) return 0;
	if (blocker(i, j - 1) && g[i][j - 1] == b) return 0;
	if (blocker(i, j + 1) && g[i][j + 1] == b) return 0;

	if (eh(i - 1, j - 1, b))
		if (g[i][j - 1] == 0 || g[i - 1][j] == 0) return 0;
	if (eh(i - 1, j + 1, b))
		if (g[i][j + 1] == 0 || g[i - 1][j] == 0) return 0;
	if (eh(i + 1, j - 1, b))
		if (g[i][j - 1] == 0 || g[i + 1][j] == 0) return 0;
	if (eh(i + 1, j + 1, b))
		if (g[i][j + 1] == 0 || g[i + 1][j] == 0) return 0;
	return 1;
}

bool place(int to_place) {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (soft_spot(i, j, to_place)) {
				print(to_place, i, j);
				return 1;
			}
	return 0;
}

signed main() {
	cin >> n;
	rep(iterations, 0, n * n) {
		int b = blocked();
		bool placed = false;
		for (int to_place = 1; to_place <= 3 && !placed; ++to_place) {
			if (to_place == b) continue;
			placed |= place(to_place);
		}
		assert(placed);
	}
}