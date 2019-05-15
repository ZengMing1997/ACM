#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
char a[maxn];
int main()
{
  int y,x,n;
  scanf("%d%d%d",&y,&x,&n);
  scanf("%s",a+1);
  int ans = 0;
  for(int i = y ; i >= y - x + 1; i--)
  {
    if(y - i  == n)
    {
      if(a[i] == '0') ans++;
    }
    else if(a[i] == '1') ans++;
  }
  cout<<ans<<endl;
}