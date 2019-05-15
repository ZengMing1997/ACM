#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
long long a[maxn];
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long ans = a[1] * a[n];
    int flag = 0;
    for(int i = 1 ; i <= n ; i++)
    {
      if(a[i] * a[n-i+1] != ans)
      {
        flag = 1;
        break;
      }
    }
    if(flag) puts("-1");
    else 
    {
      long long x = ans;
      int cur = 1;
      for(int i = 2 ; 1LL*i * i <= x ; i++)
      {
        if(x % i == 0)
        {
          int cnt = 0;
          while(x % i == 0) cnt ++ , x /= i;
          cur = cur * (1+cnt);
        }
      }
      if(x > 1)cur = cur * 2;
      if(cur -2 != n) puts("-1");
      else printf("%lld\n",ans);
    }
  }
}