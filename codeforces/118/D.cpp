#include <array>
#include <iostream>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

const int mod = 1e8, N = 101, K = 10;
int dp[N][N][2], k[2];
array<int, 2> n;
bool vis[N][N][2];

int f(array<int, 2> n, bool b) {
	if (n[0] < 0 || n[1] < 0) return 0;
	if (n[0] == 0 && n[1] == 0) return 1;

	int &x = dp[n[0]][n[1]][b];
	if (vis[n[0]][n[1]][b]) return x;
	vis[n[0]][n[1]][b] = true; --n[b];
	for (int i = 1; i <= k[b]; ++i, --n[b]) {
		x += f(n, !b);
		x %= mod;
	}
	return x;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n[0] >> n[1] >> k[0] >> k[1];
	cout << (f(n, 0) + f(n, 1)) % mod;
}