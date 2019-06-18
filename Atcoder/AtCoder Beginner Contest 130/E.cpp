#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e3+10;
const int MOD = 1e9+7;
int a[maxn] , b[maxn];
LL dp[maxn][maxn];
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
  for(int i = 1 ; i <= m ; i++) scanf("%d",&b[i]);
  for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;
  for(int i = 0 ; i <= m ; i++) dp[0][i] = 1;
  for(int i = 1 ; i <= n ; i++)
  {
    for(int j = 1 ; j <= m ; j++)
    {
      dp[i][j] = ((dp[i-1][j] + dp[i][j-1]) % MOD - dp[i-1][j-1]) % MOD;
      if(a[i] == b[j])
      {
        dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
      }
    }
  }
  cout<<((dp[n][m] % MOD) + MOD) % MOD<<endl;
}