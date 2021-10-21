#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, n; cin >> h >> w >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	vector g(h, vector(w, 0));

	int lst = 0;
	auto place = [&](int x, int y) {
		while (a[lst] == 0) ++lst;
		g[x][y] = lst + 1;
		--a[lst];
	};

	for (int i = 0; i < h; ++i) {
		if (~~i & 1) {
			for (int j = 0; j < w; ++j) {
				place(i, j);
			}
		} else {
			for (int j = w - 1; j >= 0; --j) {
				place(i, j);
			}
		}
	}

	rep(i, 0, h) {
		rep(j, 0, w)
			cout << g[i][j] << ' ';
		cout << '\n';
	}
}
