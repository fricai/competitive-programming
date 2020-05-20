#include <iostream>
using namespace std;
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

const int N = 1 << 10;
bool marked[N];
signed main() {
	ios::sync_with_stdio(false);

	int n, k, b; cin >> n >> k; b = n / k;
	rep(s, 0, b) {
		cout << 'R' << endl;
		for (int j = 0, t = s; j != b; ++j, t = (t + j) % b)
			rep(z, t * k, (t + 1) * k)
				if (!marked[z]) {
					cout << "? " << z + 1 << endl;
					char c; cin >> c;
					marked[z] = c != 'N';
				}
	}
	int ans = n; rep(z, 0, n) ans -= marked[z];
	cout << "! " << ans << endl;
}