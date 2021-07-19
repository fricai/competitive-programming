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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 7, B = 30, NC = B * N;

int t[NC][2], cnt[NC];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int nodes = 1;
	auto insert = [&](int n) {
		int root = 1; ++cnt[root];
		per(i, 0, B) {
			int &nxt = t[root][n >> i & 1];
			if (nxt == 0) nxt = ++nodes;
			++cnt[nxt];
			root = nxt;
		}
	};

	auto search = [&](int n) {
		int root = 1, cur = 0;
		--cnt[root];
		
		per(i, 0, B) {
			int bit = n >> i & 1;
			int nxt = t[root][bit];
			if (nxt == 0 || cnt[nxt] == 0) {
				bit ^= 1;
				nxt = t[root][bit];
			}
			--cnt[nxt];
			cur |= bit << i;
			root = nxt;
		}

		return cur ^ n;
	};

	int n; cin >> n;
	vector<int> a(n), p(n);
	for (auto &x : a) cin >> x;
	for (auto &x : p) cin >> x;

	for (auto x : p) insert(x);
	for (auto x : a)
		cout << search(x) << ' ';
	cout << '\n';
}