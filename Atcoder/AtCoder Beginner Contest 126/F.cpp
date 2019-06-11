#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  if(n == 1)
  {
    if(k == 0) puts("0 0 1 1");
    else puts("-1");
    return 0;
  }
  if((1<<n) <= k) {puts("-1"); return 0;}
  for(int i = 0 ; i < (1<<n) ; i++)
  {
    if(i != k) printf("%d ",i);
  }
  printf("%d ",k);
  for(int i = (1<<n) - 1 ; i >= 0 ; i--)
  {
    if(i != k) printf("%d ",i);
  }
  printf("%d ",k);
}