#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn] , vis[11];
int check()
{
  //puts("------");
  int cur = -1;
  for(int i = 1 ; i <= 10; i++)
  {
    if(vis[i])
    {
      //printf("%d %d\n",cur,vis[i]);
      if(cur == -1) cur = vis[i];
      else if(cur != vis[i]) return 0;
    }
  }
  return 1;
}
int main()
{
  int n , ans;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++)
  {
    scanf("%d",&a[i]);
    vis[a[i]]++;
    for(int j = 1 ; j <= 10 ; j++)
    {
      if(vis[j])
      {
        vis[j]--;
        if(check())
        {
          ans = i;
        }
        vis[j]++;
      }
    }
  }
  cout<<ans<<endl;
}