#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int N = 1e2, X = 1e3, Y = 1e3;
bool adj[X][Y], vis[X][Y];

void dfs(int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = 1;
    for (int y1 = 0; y1 < Y; ++y1)
        if (adj[x][y1])
            dfs(x, y1);
    for (int x1 = 0; x1 < X; ++x1)
        if (adj[x1][y])
            dfs(x1, y);
}

signed main() {
    int n; cin >> n;
    REP(i, 0, n) {
        int x, y; cin >> x >> y; --x, --y;
        adj[x][y] = 1;
    }
    
    int ans = -1;
    for (int x = 0; x < X; ++x)
        for (int y = 0; y < Y; ++y)
            if (adj[x][y] && !vis[x][y]) {
                ++ans;
                dfs(x, y);
            }
    cout << ans;
}