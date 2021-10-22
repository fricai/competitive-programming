#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int maximalRectangle(vector<vector<int> > &A) {
	vector<int> temp(sz(A[0]), 0);

	int i = 0;

	int sol = 0;

	while(i < sz(A)) {

		for(int k = 0; k < sz(A[i]); k++){
			if(A[i][k] == 0){
				temp[k] = 0;
			}
			else{
				temp[k] = temp[k] + A[i][k];
			}
		}

		stack<int> st;

		int j = 0;

		while(j < sz(temp)) {
			if(st.empty() || temp[st.top()] <= temp[j]){
				st.push(j);
				j++;
			}
			else{
				int top = st.top();
				st.pop();

				int area = 0;

				if(st.empty()){
					area = (1 + temp[top]) * (j + 1);
				}
				else{
					area = (1 + temp[top]) * (j - st.top());
				}

				sol = max(sol, area);
			}
		}

		while(!st.empty()){
			int top = st.top();
			st.pop();

			int area = 0;

			if(st.empty()){
				area = (1 + temp[top]) * (j + 1);
			}
			else{
				area = (1 + temp[top]) * (j - st.top());
			}

			sol = max(sol, area);
		}

		i++;    
	}

	return sol;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w; cin >> h >> w;
	vector<string> inp(h);
	for (auto &s : inp)
		cin >> s;

	vector g(h - 1, vector(w - 1, 0));
	rep(i, 0, h - 1) {
		rep(j, 0, w - 1) {
			g[i][j] = (1 + (inp[i][j] == '.') + (inp[i + 1][j] == '.') + (inp[i][j + 1] == '.') + (inp[i + 1][j + 1] == '.')) % 2;
		}
	}

	cout << max({h, w, maximalRectangle(g)}) << '\n';
}
