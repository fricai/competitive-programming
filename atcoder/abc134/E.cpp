#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

signed main() {
	int n; cin >> n;
	vector<int> a(n); for (auto &A : a) cin >> A;
	vector<int> head;
	for (int i = 0; i < n; ++i) {
		auto it = upper_bound(head.begin(), head.end(), -a[i]);
		if (it == head.end())
			head.push_back(-a[i]);
		else
			*it = -a[i];
	}
	cout << head.size();
}