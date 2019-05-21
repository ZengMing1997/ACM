#include <bits/stdc++.h>
using namespace std;
char ch[5] = {'a','e','i','o','u'};
int ans[1111][1111];
int main()
{
  int n;
  scanf("%d",&n);
  int L = -1,R = -1; 
  for(int i = 2 ; i * i <= n ; i++)
  {
    if(n % i == 0)
    {
      if(i >= 5 && n/i >= 5) {L = i;R = n/i;break;}
    }
  }
  //printf("%d %d\n",L,R);
  int cnt = 0;
  if(L == -1 && R == -1) {puts("-1");return 0;}
  for(int i = 1 ; i <= R ; i++)
  {
    ans[1][i] = i%5;
  }
  for(int i = 2 ; i <= L ; i++)
  {
    for(int j = 1 ; j <= R ; j++)
    {
      ans[i][j] = (ans[i-1][j] + 1) % 5;
    }
  }
  for(int i = 1 ; i <= L ; i++)
  {
    for(int j = 1 ; j <= R ; j++)
    {
      printf("%c",ch[ans[i][j]]);
    }
  }
}