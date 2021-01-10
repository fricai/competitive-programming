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

const int N = 16;
int t[2 << N];
int a[1 << N];

int win(int i, int j) {
	return a[i] > a[j] ? i : j;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, 1 << n) cin >> a[i];
	rep(i, 0, 1 << n) t[i | 1 << n] = i;
	per(i, 1, 1 << n) t[i] = win(t[i << 1], t[i << 1|1]);
	cout << (t[1] ^ t[2] ^ t[3]) + 1;
}