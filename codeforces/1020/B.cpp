#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

int main() {
    int n; cin >> n;
    int succ[n];
    REP(i, 0, n) cin >> succ[i], --succ[i];
    REP(i, 0, n) {
        int x = i;
        bool vis[n];
        REP(i, 0, n) vis[i] = 0;
        while (!vis[x]) {
            vis[x] = 1;
            x = succ[x];
        }
        cout << x + 1 << " ";
    }
}