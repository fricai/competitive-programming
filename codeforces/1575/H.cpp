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

vector<int> prefix_function(string s) {
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
    return pi;
}

void compute_automaton(string s, vector<vector<int> >& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 2; c++) {
            if (i > 0 && '0' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('0' + c == s[i]);
        }
    }
}


int main()
{
    fio;
    int n,m;
    cin>>n>>m;
    string s , t;
    cin>>s>>t;
    vector<vector<int> > aut;
    compute_automaton(t,aut);
    // for(int i=0;i<aut.size();i++){
    //     for(int j=0;j<aut[i].size();j++){
    //         cout<<aut[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    ll dp[n+1][n-m+3][m+1];
    int inf = 1e9;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-m+2;j++){
            for(int k=0;k<=m;k++){
                dp[i][j][k] = inf;
            }
        }
    }

    dp[0][0][0] = 0;
    for(int i=0;i<n;i++){

        for(int j=0;j<n-m+2;j++){
            for(int k=0;k<=m;k++){
                for(int c=0;c<2;c++){

                    if( aut[k][c] == m ){

                        if( '0' + c == s[i] ){
                            dp[i+1][j+1][aut[k][c]] = min(  dp[i+1][j+1][aut[k][c]] , dp[i][j][k] );
                        }else{
                            dp[i+1][j+1][aut[k][c]] = min(  dp[i+1][j+1][aut[k][c]] , dp[i][j][k] + 1 );
                        }

                    }else{

                        if( '0' + c == s[i] ){
                            dp[i+1][j][aut[k][c]] = min(  dp[i+1][j][aut[k][c]] , dp[i][j][k] );
                        }else{
                            dp[i+1][j][aut[k][c]] = min(  dp[i+1][j][aut[k][c]] , dp[i][j][k] + 1 );
                        }

                    }

                }
            }
        }
    }


    // for(int i=n;i<=n;i++){
    //     cout<<i<<"\n";
    //     for(int j=0;j<n-m+2;j++){
    //         cout<<j<<"\n";
    //         for(int k=0;k<=m;k++){
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    // }

    for(int i=0;i<n-m+2;i++){
        ll ans = inf;
        for(int j=0;j<=m;j++){
            ans = min(ans , dp[n][i][j]);
        }
        if( ans == inf )
            cout<<-1<<" ";
        else
            cout<<ans<<" ";
    }
    return 0;
}
