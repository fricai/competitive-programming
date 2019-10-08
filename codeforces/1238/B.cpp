#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int nmax = 1e5 + 5;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q; cin >> q;
  while (q--) {
    int n, r; cin >> n >> r;
    vector<int> x(n);
    REP(i, 0, n) cin >> x[i];
    sort(x.rbegin(), x.rend());
    x.erase(unique(x.begin(), x.end()), x.end());
    n = x.size();
    int missiles = 0;
    while (missiles < n && x[missiles] - missiles * r > 0) ++missiles;
    cout << missiles << '\n';
  }
}
