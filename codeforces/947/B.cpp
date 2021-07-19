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

template<class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> v(n), t(n);

	for (auto &x : v) cin >> x;
	for (auto &x : t) cin >> x;
	
	ll shift = 0;
	minpq<ll> q;
	rep(i, 0, n) {
		ll today = 0;
		while (!q.empty() && t[i] >= q.top() - shift) {
			today += q.top() - shift;
			q.pop();
		}
		today += ll(q.size()) * t[i];
		if (t[i] >= v[i]) today += v[i];
		else {
			today += t[i];
			q.push(v[i] + shift);
		}
		shift += t[i];

		cout << today << ' ';
	}
	cout << '\n';
}