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

const int N = 1 << 7, B = 5;
int col[N], num[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) {
		char c; cin >> c;
		if (c == 'R') col[i] = 0;
		if (c == 'G') col[i] = 1;
		if (c == 'B') col[i] = 2;
		if (c == 'Y') col[i] = 3;
		if (c == 'W') col[i] = 4;
		cin >> c;
		num[i] = c - '1';
	}

	int mn = 10;
	rep(S, 0, 1 << B) {
		rep(T, 0, 1 << B) {

			bool ok = true;
			rep(i, 0, n) {
				rep(j, i + 1, n) {
					if (col[i] == col[j] && num[i] == num[j]) continue;
					if (col[i] == col[j]) {
						if ((~S >> num[i] & 1) && (~S >> num[j] & 1)) ok = false;
					} else if (num[i] == num[j]) {
						if ((~T >> col[i] & 1) && (~T >> col[j] & 1)) ok = false;
					} else {
						if ((~T >> col[i] & 1) && (~T >> col[j] & 1) &&
							(~S >> num[i] & 1) && (~S >> num[j] & 1))
								ok = false;
					}
				}
			}

			if (ok) {
				if (ckmin(mn, __builtin_popcount(S) + __builtin_popcount(T)));
					// cerr << bitset<5>(S) << ' ' << bitset<5>(T) << '\n';
			}
		}
	}
	cout << mn;
}