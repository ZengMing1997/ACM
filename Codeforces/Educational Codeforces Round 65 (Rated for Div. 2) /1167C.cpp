#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int p[maxn],vis[maxn];
int te[maxn];
int getf(int x)
{
    return p[x] == x ? x : p[x] = getf(p[x]);
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 1 ; i <= maxn ; i++) p[i] = i;
  for(int i = 0 ; i < m ; i++)
  {
    int num;scanf("%d",&num);
    for(int i = 0 ; i < num ; i++)
    {
      scanf("%d",&te[i]);
    }
    for(int i = 1 ; i < num ; i++)
    {
      int dx = getf(te[i-1]);
      int dy = getf(te[i]);
      if(dx != dy)
      {
        p[dx] = dy;
      }
    }
  }
  for(int i = 1 ; i <= n ; i++)
  {
    vis[getf(i)]++;
  }
  for(int i = 1 ; i <= n ; i++) cout<<vis[getf(i)]<<" ";puts("");
}
/*
7 5
3 2 5 4
0
2 1 2
1 1
2 6 7
*/