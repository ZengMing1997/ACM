#include <bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
  int r,g,b,n;
  int ans = 0;
  scanf("%d%d%d%d",&r,&g,&b,&n);
  for(int i = 0 ; i * r <= n; i++)
  {
    for(int j = 0 ; j * g + i * r <= n ; j++)
    {
      if((n - j*g  - i * r) % b == 0) ans ++; 
    }
  }
  cout<<ans<<endl;
}