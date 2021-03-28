#include <bits/stdc++.h>
#include <atcoder/modint>

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

const int M = 998244353;
using mint = atcoder::static_modint<M>;

int solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    mint cur = 0, res = 0;
    rep(i, 0, n) {
        cur += cur;
        if (i) cur += a[i - 1];
        res += (cur + a[i]) * a[i];
    }
    return res.val();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    cout << solve() << '\n';
}