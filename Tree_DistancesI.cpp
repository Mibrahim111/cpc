#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
const int N = 200004;
#define INF (ll)1e18+5

int dp[N]={}, ans[N]={};
vector<int> adj[N];

void dfs1(int v,int p){
  dp[v] = 0;

  for(int ne : adj[v]){
    if(ne != p){
      dfs1(ne,v);
      dp[v] = max(dp[v],dp[ne]+1);
    }
  }
}

void dfs2(int v,int p, int up){
  ans[v] = max(dp[v],up);

  int mx1 = -1, mx2 = -1; 
  for(int i : adj[v]){
    if(i == p) continue;
    int d = dp[i] + 1;
    if(mx1 < d){mx2 = mx1 , mx1 = d;}
    else if(mx2 < d){mx2 = d;}
  }

  for(int i : adj[v]){
    if(p == i) continue;
    int take = (1 + dp[i] == mx1 ? mx2 : mx1);

    dfs2(i,v,max(1+up,1 + take));
  }
}


void solve(){

  int n;
  cin>>n;

  for(int i = 1,u,v;i < n;++i){
    cin>>u>>v;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  dfs1(1,0);
  dfs2(1,0,0);

  for(int i = 1;i <= n;++i)
  {
    cout << ans[i] << ' ';
  }

}
  

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    #endif

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
