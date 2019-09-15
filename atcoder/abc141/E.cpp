#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)

using namespace std;

signed main() {
   int n; cin >> n;
   string s; cin >> s;
   int lcs[n + 1][n + 1];
   REP(i, 0, n + 1) REP(j, 0, n + 1) lcs[i][j] = 0;
   REP(i, 1, n + 1)
       REP(j, i + 1, n + 1)
           if (s[i - 1] == s[j - 1] && lcs[i - 1][j - 1] < j - i)
               lcs[i][j] = lcs[i - 1][j - 1] + 1;
   int ans = 0;
   REP(i, 0, n + 1) REP(j, 0, n + 1) ans = max(ans, lcs[i][j]);
   cout << ans;
}