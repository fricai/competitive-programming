#include <iostream>
using namespace std;
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

const int N = 1 << 10;
bool marked[N];
signed main() {
	ios::sync_with_stdio(false);

	int n, k, b; cin >> n >> k; b = n / k;
	rep(z, 0, n) marked[z] = true;
	rep(s, 0, b) {
		cout << 'R' << endl; int d = 0;
		rep(i, 0, b) {
			int t = (s + b + d) % b;
			rep(z, t * k, (t + 1) * k)
				if (marked[z]) {
					cout << "? " << z + 1 << endl;
					char c; cin >> c;
					marked[z] = c != 'Y';
				}
			if (0 <= d) ++d; d = - d;
		}
	}
	int ans = 0; rep(z, 0, n) ans += marked[z];
	cout << "! " << ans << endl;
}