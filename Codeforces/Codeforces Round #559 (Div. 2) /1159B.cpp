#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  int ans = 0x3f3f3f3f;
  for(int i = 0 ; i < n ; i++)
  {
    int t;scanf("%d",&t);
    ans = min(ans,t/max(i,n-i-1));
  }
  cout<<ans<<endl;
}