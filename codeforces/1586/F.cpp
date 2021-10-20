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

	int n, k; cin >> n >> k;
	vector col(n, vector(n, 0));

	int ans = 0;

	auto rec = [&](const auto& self, vector<int> v, int c) -> void {
		if (sz(v) <= 1)
			return;

		int n = sz(v);
		int s = (n + k - 1) / k;


		uax(ans, c);

		// cerr << sz(v) << ' ' << c << ' ' << s << ' ' << ' ' << k << '\n';

		vector<vector<int>> chunks;
		for (int i = 0, j = 0; i < n; i = j) {
			vector<int> chunk;
			while (j < n && j - i < s) chunk.push_back(v[j++]);
			chunks.push_back(chunk);
		}
		rep(i, 0, sz(chunks)) {
			rep(j, 0, i) {
				// x < y
				for (auto x : chunks[j])
					for (auto y : chunks[i])
						col[x][y] = c;
			}
		}

		for (auto chunk : chunks) {
			self(self, chunk, c + 1);
		}
	};

	vector<int> v(n);
	iota(all(v), 0);
	rec(rec, v, 1);

	cout << ans << '\n';
	rep(u, 0, n)
		rep(v, u + 1, n)
			cout << col[u][v] << ' ';
	cout << '\n';
}
