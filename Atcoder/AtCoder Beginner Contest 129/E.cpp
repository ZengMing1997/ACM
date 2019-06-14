#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int maxn = 1e5+1000;
char ch[maxn];
int dp[maxn][2];
int main()
{
  cin>>ch+1;
  int len = strlen(ch+1);
  for(int i = 1 ; i <= len ; i++)
  {
    dp[i][0] = 3 * dp[i-1][0] + dp[i-1][1];
    dp[i][1] = 2*dp[i-1][0];
  }
}