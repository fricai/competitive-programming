#include <iostream>
#include <queue>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
    int n, m; cin >> n >> m;
    int a[n]; priority_queue<int> pq;
    REP(i, 0, n) {
        cin >> a[i];
        pq.push(a[i]);
    }
    REP(i, 0, m) {
        int x = pq.top(); pq.pop();
        pq.push(x / 2);
    }
    long long ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}