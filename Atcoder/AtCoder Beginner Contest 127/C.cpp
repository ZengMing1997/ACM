#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int sum[maxn];
int main()
{
  int n , m;
  scanf("%d%d",&n,&m);
  for(int i = 0 ; i < m ; i++)
  {
    int s,e;scanf("%d%d",&s,&e);
    sum[s]++;
    sum[e+1]--;
  }
  int te = 0 , ans = 0;
  for(int i = 1 ; i <= n ; i++)
  {
    te += sum[i];
    if(te == m) ans++;
  }
  cout<<ans<<endl;

}