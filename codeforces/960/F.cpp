#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x) ^ RANDOM; }
};

const int N = 1e5 + 10, W = 1e5 + 10;

struct {
	gp_hash_table<int, int, chash> t;
	int query(int l, int r) {
		int res = 0;
		for (l += W, r += W; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ckmax(res, t[l++]);
			if (r & 1) ckmax(res, t[--r]);
		}
		return res;
	}
	void update(int p, int v) {
		for (t[p += W] = v; p > 0; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
	}
} st[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

    int ans = 0;
	rep(e, 0, m) {
        int a, b, w; cin >> a >> b >> w;
        int cur = 1 + st[a].query(0, w);
        st[b].update(w, cur);
        ckmax(ans, cur);
    }

	cout << ans << '\n';
}