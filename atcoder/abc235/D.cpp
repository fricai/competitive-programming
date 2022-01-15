#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int K = 6, N = 1e6;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, n; cin >> a >> n;

	vector<vector<int>> g(N);

	for (int l = 1, p = 1; l <= K; ++l, p *= 10) {
		for (ll x = p; x < 10 * p; ++x) {
			if (x * a < N) g[x].push_back(x * a);
			if (x % 10 == 0) continue;
			int y = p * (x % 10) + (x / 10);
			assert(y < N);
			g[x].push_back(y);
		}
	}

	queue<int> q;
	q.push(1);
	vector<int> d(N, N);
	d[1] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : g[u]) {
			if (d[v] == N) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	cout << (d[n] < N ? d[n] : -1) << '\n';
}
