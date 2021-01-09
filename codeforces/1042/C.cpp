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

const int N = 1 << 18, inf = 2e9;
int a[N];
bool dead[N];

void type_1(int i, int j) {
	cout << "1 " << i + 1 << ' ' << j + 1 << '\n';
	dead[i] = true;
}

void type_2(int i) {
	cout << "2 " << i + 1 << '\n';
	dead[i] = true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];

	int neg = 0, zero = 0;
	rep(i, 0, n) {
		if (a[i] < 0) ++neg;
		if (a[i] == 0) ++zero;
	}

	vector<int> to_remove;
	rep(i, 0, n) if (a[i] == 0) to_remove.push_back(i);
	if (neg & 1) {
		int max_neg = -inf;
		rep(i, 0, n) if (a[i] < 0) ckmax(max_neg, a[i]);
		rep(i, 0, n) {
			if (a[i] == max_neg) {
				to_remove.push_back(i);
				break;
			}
		}
	}
	rep(i, 1, sz(to_remove)) type_1(to_remove[i], to_remove[0]);
	if (!to_remove.empty() && sz(to_remove) < n) type_2(to_remove[0]);

	int lst = -1;
	rep(i, 0, n) if (!dead[i]) lst = i;
	assert(lst != -1);
	
	rep(i, 0, lst) if (!dead[i]) type_1(i, lst);
}