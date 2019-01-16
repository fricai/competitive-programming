#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long a[n], pref[n];
    bool t[n];
    REP(i, 0, n) cin >> a[i];
    REP(i, 0, n) cin >> t[i];
    pref[0] = (!t[0])*(a[0]);
    REP(i, 1, n) pref[i] = pref[i - 1] + (!t[i])*(a[i]);
    long long index = 0, ans = pref[k - 1];
    REP(i, 1, n - k + 1) {
        if (pref[i + k - 1] - pref[i - 1] > ans) {
            ans = pref[i + k - 1] - pref[i - 1];
            index = i;
        }
    }
    ans = 0;
    REP(i, index, index + k) t[i] = 1;
    REP(i, 0, n) ans += (t[i])*(a[i]);
    cout << ans;
}