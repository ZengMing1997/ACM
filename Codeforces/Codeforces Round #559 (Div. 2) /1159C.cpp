#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int a[maxn] , b[maxn];
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  long long ans = 0 , sum = 0;
  for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]) , sum += a[i];
  for(int i = 0 ; i < m ; i++) scanf("%d",&b[i]) , ans += b[i];
  sort(a,a+n);
  sort(b,b+m);
  if(a[n-1] > b[0]) {puts("-1");return 0;}
  ans += (sum-a[n-1]) * 1LL *m;
  if(a[n-1] != b[0]) ans += a[n-1] - a[n-2];
  cout<<ans<<endl;

}