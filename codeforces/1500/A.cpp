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

const int X = 2.5e6 + 10, Y = 2 * X, N = 2e5 + 20, B = 3200;
int a[N];
vector<int> f[X];
pair<int, int> oki[Y];
bool dead[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	assert(n < N);

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[a[i]].push_back(i);
		assert(a[i] < X);
	}

	int q = 0;
	rep(x, 1, X) {
		if (sz(f[x]) > 1) {
			if (q) {
				cout << "YES\n"
					<< f[q][0] << ' ' << f[x][0] << ' '
					<< f[q][1] << ' ' << f[x][1] << '\n';
				return 0;
			} else q = x;
		}
	}

	if (q) {
		int x = f[q].back(); f[q].pop_back();
		int y = f[q].back(); f[q].pop_back();

		rep(v, 1, X) {
			// u + v = q + q
			if (f[v].empty()) continue;
			int u = q + q - v;
			if (u <= 0 || u >= X) continue;
			int z = f[v].back(); f[v].pop_back();
			if (f[u].empty()) {
				f[v].push_back(z);
				continue;
			}
			int w = f[u].back();
			assert(a[x] + a[y] == a[w] + a[z]);
			cout << "YES\n"
				<< x << ' ' << y << ' '
				<< z << ' ' << w << '\n';
			return 0;
		}

		f[q].push_back(y);
		for (auto z : f[q]) dead[z] = 1;
	}

	vector<int> v;
	for (int i = 1; i <= n; ++i)
		if (!dead[i] && sz(v) < B)
			v.push_back(i);
	rep(i, 0, sz(v)) {
		rep(j, 0, i) {
			int sum = a[v[i]] + a[v[j]];
			auto [x, y] = oki[sum];
			if (x) {
				cout << "YES\n"
					<< v[i] << ' ' << v[j] << ' '
					<< x << ' ' << y << '\n';
				return 0;
			} else oki[sum] = {v[i], v[j]};
		}
	}
	cout << "NO";
}