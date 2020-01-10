#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	int n; cin >> n;
	string s; cin >> s;
	int cnt = 0;
	rep(i, 0, n - 2)
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
			++cnt;
	cout << cnt;
}