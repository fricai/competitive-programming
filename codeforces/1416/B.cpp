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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 17;

int a[N], cur = 0;
tuple<int, int, int> moves[N];
void do_move(int i, int j, int x) {
	assert(x % i == 0);
	assert(a[i] >= x);
	a[i] -= x;
	a[j] += x;
	moves[cur++] = {i, j, x / i};
}

void print() {
	cout << cur << '\n';
	rep(i, 0, cur) {
		auto [x, y, z] = moves[i];
		cout << x << ' ' << y << ' ' << z << '\n';
	}
	cur = 0;
}

void solve() {
	cur = 0;
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
	if (sum % n != 0) return void(cout << -1 << '\n');

	int target = sum / n;
	for (int i = 2; i <= n; ++i) {
		if (a[i] % i != 0) do_move(1, i, i - a[i] % i);
		do_move(i, 1, a[i]);
	}
	for (int i = 2; i <= n; ++i) do_move(1, i, target);
	for (int i = 1; i <= n; ++i) assert(a[i] == target);
	print();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}