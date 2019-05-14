#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
vector<pair<int,int> >G[maxn];
int dp[maxn];
int dfs(int u,int fa)
{
  for(auto i:G[u])
  {
    int v = i.first, w = i.second;
    if(v == fa) continue;
    dp[u] += dfs(v,u) + w;
  }
  return dp[u];
}
int main()
{
  int n,r,k,u,v,w;
  scanf("%d%d%d",&n,&r,&k);
  for(int i = 0 ; i < n - 1 ; i ++)
  {
    scanf("%d%d%d",&u,&v,&w);
    G[u].push_back(make_pair(v,w));
    G[v].push_back(make_pair(u,w));
  }
  dfs(r,0);
  sort(dp+1,dp+n+1);
  cout<<dp[k+1]<<endl;
}