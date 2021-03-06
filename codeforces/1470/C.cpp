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

const int N = 1 << 17;

int ask(int x) {
	cout << "? " << x + 1 << endl;
	int in; cin >> in;
	return in;
}

signed main() {
	int n, k; cin >> n >> k;

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<> dis(0, n - 1);
	int idx = 0; while (ask(idx) <= k) idx = dis(rng);

	int l = 0, r = n;
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		(ask((idx + m) % n) <= k ? l : r) = m;
	}

	cout << "! " << (idx + l) % n + 1 << endl;
}