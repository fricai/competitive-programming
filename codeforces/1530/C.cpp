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

int solve() {
	int n; cin >> n;

	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	sort(all(a)); sort(rall(b));

	int sum_a = 0, sum_b = 0;
	rep(i, n / 4, n) sum_a += a[i];
	rep(i, 0, n - (n / 4)) sum_b += b[i];
	
	/*
		sum_a = sum in a[i, n)
		sum_b = sum in b[0, j)

		sum_a should have sum a[n / 4, n)
		sum_b should have sum b[0, n - (n / 4))
	*/
	
	int i = n / 4, j = n - n / 4;
	
	int added = 0;
	while (sum_a < sum_b) {
		++n; ++added;
		
		a.push_back(100);
		sum_a += 100;

		b.push_back(0);

		while (i < n / 4) sum_a -= a[i++];
		while (j < n - (n / 4)) sum_b += b[j++];		
	}
	
	return added;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}