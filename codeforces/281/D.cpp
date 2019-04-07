#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

int solve(const vector<int> &s) {
	vector<int> st;
	int ans = s[0]^s[1], n = s.size();
	REP(i, 0, n) {
		while(!st.empty() && st.back() < s[i]) st.pop_back();
		st.emplace_back(s[i]);
		if (st.size() > 1) ans = max(ans, st[st.size() - 1]^st[st.size() - 2]);
	}
	return ans;
}

int main() {
	int n; cin >> n;
	vector<int> s(n);
	REP(i, 0, n) cin >> s[i];
	int ans = solve(s);
	reverse(s.begin(), s.end());
	cout << max(ans, solve(s)) << '\n';
}
