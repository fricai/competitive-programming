#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int mod = 998244353;

string s;
pair<int,int> dp[100][10][10][2][2][1 << 8];
int vs;
int A, B;
char id[2][10];
bool is[256];

int transition(int i, int ca, int cb, bool ga, bool gb, int mask){
	mask &= ~(1 << 8);
	if(i == s.size())
		return ca == cb && ga + gb == 0 && is[mask];
	auto &R = dp[i][ca][cb][ga][gb][mask];
	if (R.second == vs)
		return R.first;
	R.second = vs;
	int &ret = R.first;
	ret = 0;
	for (int da = 0; da <= 9; ++da){
		for(int db = 0;db <= 9; ++db){
			int AA=(da * A + ca);
			int BB=(db * B + cb);
			if(AA % 10 != BB % 10)
				continue;
			ret += transition(i+1,AA/10,BB/10,
			da > s[i] || (ga && da >= s[i]),
			db > s[i] || (gb && db >= s[i]),
			mask | (1<<id[0][da]) | (1 << id[1][db]));
			ret %= mod;
		}
	}
	return ret;
}
signed main() {
	cin>>s;
	int res = 0;
	for(int i = 0; i < s.size(); ++i)
		res = (res * 10ll + s[i] - '0') % mod;
	reverse(s.begin(), s.end());
	for(auto &x : s)
		x -= '0';
	set<pair<int,int>> v;
	map<pair<int,int>, pair<set<int>, set<int>>> freq;
	for(int a = 1; a <= 9; ++a)
		for(int b = 1; b <= 9; ++b){
			if(a == b)
				continue;
			int c = __gcd(a,b);
			v.insert({a / c, b / c});
			freq[{a / c, b / c}].first.insert(a);
			freq[{a / c, b / c}].second.insert(b);
		}
	for (auto &x : v){
		A = x.second;
		B = x.first;
		++vs;
		memset(id, 8, sizeof(id));
		int w = 0;
		for (auto &x : freq[x].first)
			id[0][x] = w++;
		for(auto &x : freq[x].second)
			id[1][x] = w++;
		memset(is, 0, sizeof(is));
		for(int mask = 0; mask < 256; ++mask){
			for(int i = 1; i <= 9; ++i)
				for(int j = 1; j<=9; ++j){
					int c = __gcd(i,j);
					if(i / c == x.first && j / c == x.second){
						if ((mask >> id[0][i]) & 1)
							if ((mask >> id[1][j]) & 1)
								is[mask] = true;
					}
				}
		}
		res += transition(0, 0, 0, false, false, 0);
		res %= mod;
	}
	cout << res;
}