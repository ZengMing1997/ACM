#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++)
  {
    scanf("%d",&a[i]);
    a[i] = abs(a[i]);
  }
  sort(a,a+n);
  long long ans = 0;
  for(int i = 0 ; i < n ; i++)
  {
    ans += upper_bound(a+i+1,a+n,2*a[i]) - a - i-1;
  }
  cout<<ans<<endl;
}