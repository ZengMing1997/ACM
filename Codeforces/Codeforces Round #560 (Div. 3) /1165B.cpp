#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  int ans = 0 , cnt = 1;
  for(int i = 0 ; i < n ; i++)
  {
    if(cnt <= a[i]) cnt++,ans++;
  }
  printf("%d\n",ans);
}