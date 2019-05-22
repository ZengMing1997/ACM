#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
vector<int>V[55];
int vis[maxn];
int main()
{
  int m , n;
  scanf("%d%d",&m,&n);
  for(int i = 0 ; i < m ; i++)
  {
    int t;scanf("%d",&t);
    for(int j = 0 ; j < t ; j++)
    {
      int x;scanf("%d",&x);
      V[i].push_back(x);
    }
  }
  for(int i = 0 ; i < m ; i++)
  {
    for(int j = i + 1 ; j < m ; j++)
    {
      int flag = 0;
      memset(vis,0,sizeof(vis));
      for(int k : V[i]) vis[k] = 1;
      for(int k : V[j])
      {
        if(vis[k]) flag = 1;
      }
      if(flag == 0) {puts("impossible");return 0;}
    }
  }
  puts("possible");
}