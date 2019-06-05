#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000+500;
int a[maxn];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < 2*n ; i++)
  {
    scanf("%d",&a[i]);
  }
  sort(a,a+2*n);
  int sum1 = 0 , sum2 = 0;
  for(int i = 0 ; i < 2 * n ; i++)
  {
    if(i < n) sum1 += a[i];
    else sum2 += a[i];
  }
  if(sum1 != sum2)
  {
    for(int i = 0 ; i < 2 * n ; i++) printf("%d ",a[i]);
  }
  else puts("-1");
}