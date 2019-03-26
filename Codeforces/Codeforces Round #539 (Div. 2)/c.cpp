#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
long long sum[maxn];
int num[(1LL<<20)][2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
    {
        long long t;scanf("%lld",&t);
        sum[i] = sum[i-1]^t;
    }
    long long ans = 0;
    num[0][0] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        ans += num[sum[i]][i&1];
        num[sum[i]][i&1]++;
    }
    cout<<ans<<endl;

}