#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;
char s[maxn][maxn];
int dp1[maxn][maxn],dp2[maxn][maxn],dp3[maxn][maxn],dp4[maxn][maxn];
int main()
{
  int n , m ;
  scanf("%d%d",&n,&m);
  for(int i = 1 ; i <= n ; i++)
  {
    scanf("%s",s[i]+1);
  }
  for(int i = 1 ; i <= n ; i++)
  {
    for(int j = 1 ; j <= m ; j++)
    {
      if(s[i][j] == '.')
        dp1[i][j] = dp1[i-1][j] + 1 , dp2[i][j] = dp2[i][j-1]+1;
    }
  }
  for(int i = n ; i >= 1 ; i--)
  {
    for(int j = m ; j >= 1 ; j--)
    {
      if(s[i][j] == '.')
        dp3[i][j] = dp3[i+1][j] + 1 , dp4[i][j] = dp4[i][j+1] + 1;
    }
  }
  int ans = 0;
  for(int i = 1 ; i <= n ; i++)
  {
    for(int j =  1 ; j <= m ; j++)
    {
      if(s[i][j] == '.') ans = max(ans,dp1[i][j] + dp2[i][j] + dp3[i][j] + dp4[i][j] - 3);
    }
  }
  cout<<ans<<endl;
}
/*
4 6
#..#..
.....#
....#.
#.#...
 */