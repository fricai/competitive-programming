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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;

	int count = 0;
	rep(i, 0, 10) {
		rep(j, 0, 10) {
			rep(k, 0, 10) {
				rep(l, 0, 10) {
					vector<int> pin = {i, j, k, l};

					bool ok = 1;
					rep(r, 0, 10) {
						if (s[r] == '?') continue;
						auto it = find(all(pin), r);
						if (s[r] == 'x' && it != end(pin)) ok = 0;
						if (s[r] == 'o' && it == end(pin)) ok = 0;
					}
					
					count += ok;
				}
			}
		}
	}

	cout << count << '\n';
}