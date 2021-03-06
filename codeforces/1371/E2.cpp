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
int f[N + N];

int mod(int x, int p) {
	x %= p; if (x < 0) x += p;
	return x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p; cin >> n >> p;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(all(a));

	int X = a.back();
	for (int x = max(1, X - n), k = 0, i = 0; x < X + n; ++x, ++i) {
		while (k < n && a[k] <= x) ++k;
		f[i] = k;
	}
	
	multiset<int> s;
	vector<int> op;
	for (int x = max(1, X - n), y = x, i = 0, j = 0; x <= X; ++x, ++i) {
		for (; y - x < n; ++y, ++j) s.insert(mod(y - f[j], p));
		if (!s.count(x % p)) op.push_back(x);
		s.erase(s.find(mod(x - f[i], p)));
	}

	cout << sz(op) << '\n';
	for (auto x : op) cout << x << ' ';
}