#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector<string> A(n), B(m);
	for (auto &a : A) cin >> a;
	for (auto &b : B) cin >> b;

	if (n > m) swap(A, B);
	sort(B.begin(), B.end());
	bool k = 0;
	for (auto &a : A) k ^= binary_search(B.begin(), B.end(), a);
	cout << ((n + k > m) ? "YES" : "NO") << '\n';
}
