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

constexpr int inf = 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w; cin >> h >> w;
	vector<string> s(h);
	for (auto &row : s)
		cin >> row;

	auto get = [&](int i, int j) { return i * w + j; };
	auto check = [&](int i, int j) { return 0 <= i && i < h && 0 <= j && j < w; };

	vector<int> d(h * w, inf);
	deque<int> q;
	q.push_front(0);
	d[0] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();

		auto op = [&](int i, int j, int w) -> void {
			if (!check(i, j))
				return;
			if (w == 0 && s[i][j] == '#')
				return;
			int v = get(i, j);
			if (uin(d[v], d[u] + w)) {
				if (w == 1)
					q.push_back(v);
				else
					q.push_front(v);
			}
		};

		int i = u / w, j = u % w;
		op(i + 1, j, 0);
		op(i - 1, j, 0);
		op(i, j + 1, 0);
		op(i, j - 1, 0);
		for (int x : {-2, -1, 0, +1, +2})
			for (int y : {-2, -1, 0, +1, +2})
				if (abs(x) != 2 || abs(y) != 2)
					op(i + x, j + y, 1);
	}
	cout << d.back() << '\n';
}
