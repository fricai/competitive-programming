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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int A = 26;

int ans(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return *max_element(all(pi));
}

string solve() {
	string s; cin >> s;
	int n = sz(s);
	
	if (n <= 2) {
		sort(all(s));
		return s;
	}
	
	vector<int> f(A);
	for (auto x : s) ++f[x - 'a'];

	for (auto x : f)
		if (x == n)
			return s;
	
	int fst = -1;
	per(i, 0, A)
		if (f[i] == 1)
			fst = i;
	
	if (fst >= 0) {
		auto it = find(all(s), fst + 'a');
		s.erase(it);
		sort(all(s));
		string t = string(1, fst + 'a') + s;

		assert(ans(t) == 0);
		
		return t;
	}

	per(i, 0, A)
		if (f[i])
			fst = i;
	
	if (f[fst] - 2 <= (n - 2) / 2) {
		string t(2, 'a' + fst);
		
		f[fst] -= 2;
		int i = 0;
		while (f[fst] > 0) {
			while (i < A && (i == fst || f[i] == 0)) ++i;
			
			assert(i < A);
			
			t.push_back(i + 'a');
			t.push_back(fst + 'a');
			
			--f[i]; --f[fst];
		}
		
		while (i < A) {
			while (f[i] > 0) {
				--f[i];
				t.push_back(i + 'a');
			}
			++i;
		}
		
		assert(sz(t) == n);
		assert(ans(t) == 1);
		return t;
	}
	int a = fst, b = fst + 1;
	while (f[b] == 0) ++b;
	// start with ab
	/*
		Now ab must not occur again,
	*/
	
	int c = b + 1;
	while (c < A && f[c] == 0) ++c;
	string t;
	auto add = [&](int x) {
		char c = x + 'a';
		assert(f[x]);
		--f[x]; t.push_back(c);
	};
	add(a); add(b);
	
	if (c < A) {
		while (f[a] > 0) add(a);
		add(c);
		rep(i, a + 1, A)
			while (f[i] > 0)
				add(i);
	} else {
		while (f[b] > 0) add(b);
		while (f[a] > 0) add(a);		
	}

	assert(sz(t) == n);
	assert(ans(t) == 1);
	return t;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		auto s = solve();
		// cerr << ans(s) << '\n';
		cout << s << '\n';
	}
}