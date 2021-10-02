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
    int n,m,k;
    cin>>n>>m>>k;

    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    // vector<int> ans;
    for(int i=0;i<k;i++){
        int r = 0;
        int c;
        cin>>c;
        --c;
        while( r != n ){
            // cout<<r<<c<<"\n";
            int nr,nc;
            if( mat[r][c] == 1){
                nr = r;
                nc = c+1;
            }else if( mat[r][c] == 2){
                nr = r+1;
                nc = c;
            }else{
                nr = r;
                nc = c-1;
            }
            mat[r][c] =2;
            r = nr;
            c = nc;
        }
        cout<<c+1<<" ";
    }
    
    return 0;
}
