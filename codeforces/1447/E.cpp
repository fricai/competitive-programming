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

const int N = 1 << 18, B = 30, NC = B * N;
int l[NC], r[NC], t[NC], c = 1;

void insert(int x) {
	int cur = 1;
	per(j, 0, B) {
		auto &child = x >> j & 1 ? r[cur] : l[cur];
		if (child == 0) child = ++c;
		cur = child;
		++t[cur];
	}
}

int dfs(int u) { return u ? min(t[l[u]] + dfs(r[u]), t[r[u]] + dfs(l[u])) - 1 : 0; }

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	t[0] = 1;
	int n; cin >> n;
	rep(i, 0, n) {
		int x; cin >> x;
		insert(x);
	}
	cout << dfs(1);
}