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
bool dead[N];
int L[N], R[N];

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	rep(i, 0, n) R[i] = i + 1, dead[i] = 0;
	R[n - 1] = 0;
	
	queue<int> q;
	rep(i, 0, n) if (gcd(a[i], a[R[i]]) == 1) q.push(i);

	vector<int> res;
	while (!q.empty()) {
		queue<int> p;
		auto f = [&](int i) { if (gcd(a[i], a[R[i]]) == 1) p.push(i); };
		while (!q.empty()) {
			auto i = q.front(); q.pop();
			if (dead[i]) continue;
			res.push_back(R[i]);
			dead[R[i]] = 1;
			R[i] = R[R[i]];
			f(i);
		}
		swap(p, q);
	}
	cout << sz(res) << ' ';
	for (auto x : res) cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}