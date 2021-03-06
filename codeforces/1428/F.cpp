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

const int N = 1 << 19;
int n;
int f[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> n >> s;
	ll ans = 0, cur = 0;
	for (int i = 0, j = 0; i < n; i = j) {
		if (s[i] == '0') { ans += cur; ++j; continue; }
		
		while (j < n && s[j] == '1') ++j;
		for (int c = 1; c <= j - i; ++c) {
			cur += i + c - f[c];
			ans += cur;
			f[c] = j - c + 1;
		}
	}

	cout << ans;
}