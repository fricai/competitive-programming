#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int M = 119 << 23 | 1;

int mul(ll x, int y) { return x * y % M; }
int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }
void inc(int &x, int y) { x += y; if (M <= x) x -= M; }
int bpow(int a, ll b) {
	int res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1)
			res = mul(res, a);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, A, h; cin >> k >> A >> h;


	int n = (1 << (k - 1));

	// 2n teams
	
	auto construct = [](int n, int S, int pos) {
		vector<int> t(n + n);
		iota(end(t) - n, end(t), 0);
		per(i, 1, n)
			t[i] = t[i << 1 | (S >> (i - 1) & 1)];
		
		int counter = 1;
		vector<int> rnk(n);
		rep(i, 1, n + n) {
			if (rnk[t[i]] == 0) {
				rnk[t[i]] = pos;
				counter += 2;
			}
			if ((i & (i + 1)) == 0)
				pos = counter;
		}
		return rnk;
	};

	map<int, int> f;
	rep(S, 0, 1 << (n - 1)) {
		auto rnk = construct(n, S, 2);
		int score = 0;
		rep(i, 0, n)
			inc(score, mul(i + 1, bpow(A, rnk[i])));
		f[score] = S;
	}

	rep(S, 0, 1 << (n - 1)) {
		auto rnk = construct(n, S, 1);
		int score = 0;
		rep(i, 0, n)
			inc(score, mul(i + n + 1, bpow(A, rnk[i])));
		int other = sub(h, score);
		auto it = f.find(other);
		if (it == end(f))
			continue;
		for (auto x : construct(n, it->second, 2))
			cout << x << ' ';
		for (auto x : rnk)
			cout << x << ' ';
		cout << '\n';
		return 0;
	}

	f.clear();
	rep(S, 0, 1 << (n - 1)) {
		auto rnk = construct(n, S, 2);
		int score = 0;
		rep(i, 0, n)
			inc(score, mul(i + n + 1, bpow(A, rnk[i])));
		f[score] = S;
	}
	rep(S, 0, 1 << (n - 1)) {
		auto rnk = construct(n, S, 1);
		int score = 0;
		rep(i, 0, n)
			inc(score, mul(i + 1, bpow(A, rnk[i])));
		int other = sub(h, score);
		auto it = f.find(other);
		if (it == end(f))
			continue;
		for (auto x : rnk)
			cout << x << ' ';
		for (auto x : construct(n, it->second, 2))
			cout << x << ' ';
		cout << '\n';
		return 0;
	}
	cout << "-1\n";
}
