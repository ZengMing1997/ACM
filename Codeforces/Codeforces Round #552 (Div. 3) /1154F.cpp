#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn] , sp[maxn];
long long sum[maxn] , dp[maxn];
int main()
{
    int n , m , k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i = 1 ; i <= m ; i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        sp[x] = max(sp[x],y);
    }
    for(int i = 1 ; i <= min(n,2000) ; i++) sum[i] = sum[i-1] + a[i];
    for(int i = 1 ; i <= k ; i++)
    {
        dp[i] = dp[i-1] + a[i];
        for(int j = 0 ; j < i ; j ++)
        {
            dp[i] = min(dp[i] , dp[j] + sum[i] - sum[j+sp[i-j]]);
        }
    }
    printf("%d\n",dp[k]);
}