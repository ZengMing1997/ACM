#include <bits/stdc++.h>
using namespace std;
const int maxn = 111;
int a[maxn];
int main()
{
  int n;
  scanf("%d",&n);
  int sum = 0;
  for(int i = 0 ; i < n ; i++)
  {
    scanf("%d",&a[i]);
    sum += a[i];
  }
  int ans = 100000;
  for(int i = 1 ; i < n ; i++)
  {
    int t1 = 0 , t2 = 0;
    for(int j = 0 ; j <= i ; j++)
    {
      t1 += a[j];
    }
    t2 = sum - t1;
    ans = min(ans,abs(t2-t1));
  }
  cout<<ans<<endl;
}