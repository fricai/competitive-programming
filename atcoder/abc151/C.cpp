#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define dbg(x) #x << ": " << x <<
#define sz(x) ((int)x.size())

const int N = 1e5;
int ac[N + 1], wa[N + 1];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, m) {
		int p; cin >> p; string s; cin >> s; --p;
		if (s == "AC") ++ac[p];
		else if (ac[p] == 0) ++wa[p];
	}

	int correct = 0, penalty = 0;
	rep(i, 0, n)
		if (ac[i] > 0) {
			++correct;
			penalty += wa[i];
		}
	cout << correct << ' ' << penalty << ' ';
}