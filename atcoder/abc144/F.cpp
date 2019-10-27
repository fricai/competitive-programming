
#include<iostream>
#include<iomanip>
#define REP(i,a,b) for(auto i=(a);i<(b);++i)
using namespace std;const int inf=1e9,N=600;bool adj[N][N];int deg[N];double E[N][2];signed main(){ios_base::sync_with_stdio(0);cin.tie(NULL);int n,m;cin>>n>>m;while(m--){int s,t;cin>>s>>t;--s,--t;adj[s][t]=1;++deg[s];}auto solve=[&](bool b){REP(k,1,n){int i=n-k-1;E[i][b]=0;REP(j,i+1,n-1)if(adj[i][j])E[i][b]+=E[j][b];E[i][b]/=deg[i];++E[i][b];}};solve(0);double ans=E[0][0];REP(i,0,n-1){if(deg[i]==1) continue;int mxpos;double mx=-1;REP(j,i+1,n)if(adj[i][j])if(mx<E[j][0]){mxpos=j;mx=E[j][0];}--deg[i];adj[i][mxpos]=0;solve(1);++deg[i];adj[i][mxpos]=1;ans=min(ans,E[0][1]);}cout<<setprecision(10)<<ans;}
