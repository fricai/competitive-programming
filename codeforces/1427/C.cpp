#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1 << 18;
int x[N], y[N], dp[N], t[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int r, n;
	cin >> r >> n;
    x[0] = y[0] = 1;
    fill(dp + 1, dp + n + 1, -1e9);
	for(int i = 1; i <= n; i++)
		cin >> t[i] >> x[i] >> y[i];
    for(int i = 1; i <= n; i++) {
        for(int j = max(0, i - 5 * r); j < i; j++) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]); 
	cout << ans;
}
