#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
int a[maxn];
LL sum[maxn];
int main()
{
  int n;
  LL k;
  scanf("%d%lld",&n,&k);
  for(int i = 1 ; i <= n ; i++)
  {
    scanf("%d",&a[i]);
    sum[i] = sum[i-1] + a[i];
  }
  LL ans = 0;
  for(int i = 0 ; i <= n ; i++)
  {
    int pos = lower_bound(sum+i,sum+n+1,1LL*k + sum[i]) - sum;
    ans += n - pos + 1;
  }
  cout<<ans<<endl;
}