#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define pll pair<ll,ll>
#define mp make_pair
#define f first
#define s second 
# define fio ios_base::sync_with_stdio(false); cin.tie(NULL)

const int MAX_N = 2e5;
ll mod = 998244353;


int main()
{
    fio;
    int n,m;
    cin>>n>>m;
    vector<string> v;
    map<string,int> ma; 
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int i=1;i<s.length();i+=2){
            int c = s[i] - 'A';
            s[i] = (char)( 'A' + (25 - c) );
        }
        ma[s]= i+1;
        // cout<<s<<"\n";
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<ma[v[i]]<<" ";
    }
    return 0;
}
