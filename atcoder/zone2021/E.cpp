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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

template<class T>
using pq = __gnu_pbds::priority_queue<T, greater<T>, __gnu_pbds::thin_heap_tag>;
using S = tuple<ll, int, int>;

const int N = 1 << 9;
const ll inf = 1e18;
int a[N][N], b[N][N];
pq<S>::point_iterator it[N][N];
pq<S> q;
bool vis[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int r, c; cin >> r >> c;

	for (int i = 1; i <= r; ++i)
		rep(j, 1, c)
			cin >> a[i][j];
	
	rep(i, 1, r)
		for (int j = 1; j <= c; ++j)
			cin >> b[i][j];
	
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			it[i][j] = q.push({inf, i, j});

	auto relax = [&](int i, int j, ll d) {
		if (vis[i][j]) return;
		if (d < get<0>(*it[i][j]))
			q.modify(it[i][j], {d, i, j});
	};

	q.modify(it[1][1], {0, 1, 1});
	
	while (!q.empty()) {
		auto [d, i, j] = q.top();
		q.pop();

		if (i == r && j == c) {
			cout << d << '\n';
			return 0;
		}

		assert(!vis[i][j]);
		vis[i][j] = 1;
		
		if (j < c) relax(i, j + 1, d + a[i][j]);
		if (j > 1) relax(i, j - 1, d + a[i][j - 1]);
		if (i < r) relax(i + 1, j, d + b[i][j]);

		for (int k = 1; k < i; ++k)
			relax(i - k, j, d + k + 1);
		
	}
	
	assert(0);
}