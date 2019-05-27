#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
long long a[maxn] , b[maxn],c[maxn];
int main()
{
    int n ,m;
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ;i++) scanf("%lld",&a[i]);
    for(int i = 1 ; i <= m ;i++) scanf("%lld",&c[i]);
    long long ans = 0;
    for(int i = n ; i >= 2 ; i --) ans = __gcd(ans,a[i] - a[i-1]);
    for(int i = 1 ; i <= m ; i++)
    {
        if(ans % c[i]== 0)
        {
            printf("YES\n%lld %d\n",a[1], i);
            return 0;
        }
    }
    puts("NO");
}