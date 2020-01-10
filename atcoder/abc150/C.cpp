#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int mod = 1e9 + 7;

int rk(const vi &a) {
	vi b(a);
	sort(b.begin(), b.end());
	int res = 0;
	do {
		++res;
		if (a == b) return res;
	}	while (next_permutation(b.begin(), b.end()));
	return res;
}

signed main() {
	int n; cin >> n;
	vi p(n), q(n);
	for (auto &x : p) cin >> x;
	for (auto &x : q) cin >> x;
	cout << abs(rk(p) - rk(q));
}