#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
vector<pair<int,int> > G[maxn];
int Ans[maxn];
void dfs(int u,int fa,int sum)
{
  //cout<<u<<"  " << sum<<endl;
  if(sum & 1) Ans[u] = Ans[0]^1;
  else Ans[u] = Ans[0];
  for(auto i : G[u])
  {
    int v = i.first , w = i.second;
    if(v == fa) continue;
    dfs(v,u,sum+w);
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n - 1 ; i ++)
  {
    int u,v,w;scanf("%d%d%d",&u,&v,&w);
    G[u].emplace_back(v,w);
    G[v].emplace_back(u,w);
  }
  //puts("----");
  Ans[0] = 0;
  dfs(1,0,0);
  for(int i = 1 ; i <= n ; i++) cout<<Ans[i]<<" ";puts("");
}