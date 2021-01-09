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

const int N = 1 << 18;
int n, a[N], b[N], p[N], inv[N], ord[N];
vector<pair<int, int>> op;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(j, 0, n) cin >> p[j], --p[j], inv[p[j]] = j;

    bool impossible = false;
    rep(i, 0, n) if (p[i] != i && a[i] <= b[p[i]]) impossible = true;
    if (impossible) return cout << "-1", 0;
    
    rep(i, 0, n) ord[i] = i;
    sort(ord, ord + n, [&](int x, int y) { return a[x] < a[y]; });

    rep(k, 0, n) {
        int i = ord[k];
        if (p[i] == i) continue;
        int j = inv[i];
        op.emplace_back(i, j);
        inv[i] = i;
        p[j] = p[i];
        inv[p[j]] = j;
    }
    cout << sz(op) << '\n';
    for (auto [i, j] : op) cout << i + 1 << ' ' << j + 1 << '\n';
}