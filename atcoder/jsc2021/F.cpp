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

const int N = 1 << 18, M = N, Q = N;
int t[Q], x[Q], y[Q], a[N], b[M];
vector<int> cmp;

struct S {
	int c = 0;
	ll s = 0;
};
S& operator+=(S &a, const S &b) {
	a.c += b.c;
	a.s += b.s;
	return a;
}
S operator+(S a, const S &b) { return a += b; }

int H(int x) { return lb(all(cmp), x) - begin(cmp); }

const int Z = N;
struct T {
	S t[Z << 1];
	void update(int p, S v) {
		for (t[p += Z] += v; p >>= 1; )
			t[p] = t[p << 1] + t[p << 1|1];
	}

	S query(int l, int r) {
		S res = {0, 0};
		for (l += Z, r += Z; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res += t[l++];
			if (r & 1) res += t[--r];
		}
		return res;
	}
} u, v;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;

	cmp = {0};
	rep(i, 0, q) {
		cin >> t[i] >> x[i] >> y[i];
		cmp.push_back(y[i]);
	}
	sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));
	rep(i, 0, n) u.update(H(0), {+1, 0});
	rep(i, 0, m) v.update(H(0), {+1, 0});

	ll ans = 0;

	auto f = [&](ll x) {
		ll cur = 0;
		int split = H(x);
		cur += v.query(0, split).c * x;
		cur += v.query(split, Z).s;
		return cur;
	};
	
	auto g = [&](ll x) {
		ll cur = 0;
		int split = H(x);
		cur += u.query(0, split).c * x;
		cur += u.query(split, Z).s;
		return cur;
	};

	rep(i, 0, q) {
		--x[i];
		if (t[i] == 1) {
			auto &z = a[x[i]];
			int j;

			ans -= f(z);
			j = H(z);
			u.update(j, {-1, -z});
			z = y[i];

			ans += f(z);
			j = H(z);
			u.update(j, {+1, +z});
		} else {
			auto &z = b[x[i]];
			int j;

			ans -= g(z);
			j = H(z);
			v.update(j, {-1, -z});
			z = y[i];
			
			ans += g(z);
			j = H(z);
			v.update(j, {+1, +z});
		}
		cout << ans << '\n';
	}
}