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

const int A = 26, N = 1 << 18;
vector<int> pos[A];
int p[N];

ll dnc(int l, int r) {
	if (r - l == 1) return 0;
	int m = (l + r) / 2;
	ll res = dnc(l, m) + dnc(m, r);
	for (int i = l, j = m, k = l; i < m && j < r; ++k) 
		if (p[i] > p[j]) j++, res += m - i; else ++i;
	inplace_merge(p + l, p + m, p + r);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	string s; cin >> s;
	rep(i, 0, n) pos[s[i] - 'a'].eb(n - i - 1);
	rep(i, 0, n) {
		p[i] = pos[s[i] - 'a'].back();
		pos[s[i] - 'a'].pop_back();
	}
	cout << dnc(0, n);
}