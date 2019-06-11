#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int p[maxn];
int getf(int v)
{
  return p[v] == v ? v : p[v] = getf(p[v]);
}
int main()
{
  int n , m ;
  scanf("%d%d",&n,&m);
  for(int i = 1 ; i <= n ; i++) p[i] = i; 
  for(int i = 0 ; i < m ; i++)
  {
    int u , v , w;scanf("%d%d%d",&u,&v,&w);
    int dx = getf(u);
    int dy = getf(v);
    if(p[dx] != p[dy])
    {
      p[dx] = dy;
    }
  }
  int ans = 0;
  for(int i = 1 ; i <= n ; i++)
  {
    if(p[i] == i) ans ++;
  }
  cout<<ans<<endl;
}