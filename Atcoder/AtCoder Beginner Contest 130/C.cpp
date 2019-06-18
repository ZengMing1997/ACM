#include <bits/stdc++.h>
using namespace std;
int main()
{
  int W , H , x , y;
  scanf("%d%d%d%d",&W,&H,&x,&y);
  printf("%.10f ",1LL*W*1.0*H/2.0);
  if(W/2.0 == x && H/2.0 == y)
  {
    puts("1");
  }
  else puts("0");
}