#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int p[maxn],vis[maxn];
int getf(int x)
{
  return x == p[x] ? x : p[x] = getf(p[x]);
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 1 ; i <= n ; i++) p[i] = i;
  for(int i = 0 ; i < m ; i++)
  {
    int num;scanf("%d",&num);
    int t;scanf("%d",&t);
    num--;
    while(num--)
    {
      int t1;scanf("%d",&t1);
      int dx = getf(t);
      int dy = getf(t1);
      if(dx != dy)
      {
        p[dx] = dy;
      }
      t = t1;
    }
  }
  for(int i = 1 ; i <= n ; i++)
  {
    vis[getf(i)]++;
  }
  for(int i = 1 ; i <= n ; i++) cout<<vis[getf(i)]<<" ";puts("");
}