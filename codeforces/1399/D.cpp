#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 18;
vector<int> head[2];
int a[N];

void solve() {
	int n; string s; cin >> n >> s;
	
	int cnt = 0;
	head[0] = head[1] = { };

	rep(i, 0, n) {
		int x = s[i] - '0';
		if (head[1 - x].empty()) head[x].eb(++cnt);
		else {
			head[x].eb(head[1 - x].back());
			head[1 - x].pop_back();
		}
		a[i] = head[x].back();
	}
	cout << cnt << '\n';
	rep(i, 0, n) cout << a[i] << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}