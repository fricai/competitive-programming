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

const int N = 1 << 17;
pair<ld, ld> E[N << 1];
int a[N];
bool dead[N];

template<class T>
pair<T, T>& operator-=(pair<T, T>& a, const pair<T, T> &b) {
	a.first -= b.first;
	a.second -= b.second;
	return a;
}


template<class T>
pair<T, T>& operator+=(pair<T, T>& a, const pair<T, T> &b) {
	a.first += b.first;
	a.second += b.second;
	return a;
}

const ld eps = 1e-9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >> n >> m >> k;
	rep(i, 0, k) {
		cin >> a[i];
		dead[a[i]] = true;
		E[a[i]] = {0, 1};
	}

	pair<ld, ld> cur = {0, 0};
	per(i, 0, n) {
		if (!dead[i]) E[i] = {1 + cur.first / m, cur.second / m};
		cur -= E[i + m];
		cur += E[i];
	}
	
	auto bot = 1 - E[0].second;
	if (bot < eps) cout << -1;
	else cout << fixed << setprecision(10) << E[0].first / bot;
}