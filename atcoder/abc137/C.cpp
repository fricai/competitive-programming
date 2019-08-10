#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> m;
    
    for (int i = 0; i < n; ++i) {
        string S; cin >> S;
        sort(S.begin(), S.end());
        ++m[S];
    }
    long long ans = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        long long x = (*it).second;
        ans += (x * (x - 1))/2;
    }
    cout << ans;
}