#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
typedef long long LL;
const int MOD = 1e9 + 7;
int n;
LL dp[MAXN][MAXN];
int main()
{
	scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        dp[i][0] = dp[i - 1][0] + i % 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + (i + j) % 2) % MOD;
        }
    }
    printf("%lld\n", dp[n][n]);
	return 0;
}
/*
2
*/