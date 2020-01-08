#include <iostream>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

string s;
string t = "";

void f(int l, int r) {
	if (l > r) return;
	if (r - l <= 2) t += s[l];
	else {
		string x;
		if (s[l] == s[r] || s[l] == s[r - 1]) x = string(1, s[l]);
		else x = string(1, s[l + 1]);
		t += x; f(l + 2, r - 2); t += x;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	int n = s.size();
	f(0, n - 1);
	cout << t;
}