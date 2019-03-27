#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e6+10;
long long fac[maxn] , inv[maxn];
long long qpow(long long a , int b)
{
    if(b < 0) return qpow(a,b+mod-1);
    long long ans = 1;
    while(b)
    {
        if(b&1) ans = ans * a % mod;
        a = a * a % mod;
        b = b/2;
    }
    return ans;
}
void getFac(int n)
{
    for (int i = fac[0] = 1; i <= n; i++) fac[i] = fac[i-1] * i %mod;
    inv[n]=qpow(fac[n],mod-2);
    for(int i=n; i >= 1; i--) inv[i-1]=inv[i]*i%mod;
}
long long getC(long long n , long long m)
{
    if(n < m|| m < 0) return 0;
    return fac[n] * inv[n-m] % mod * inv[m] % mod;
}
int main()
{
    long long n,m,a,b;
    scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
    getFac(max(n,m));
    long long ans = 0;
    for(long long i = 0 ; i <= n - 2; i++)
    {
        ans = (ans + getC(n-2,i)* getC(m-1,i)%mod*fac[i]%mod *qpow(m,n-2-i)%mod * qpow(n,n-i-3)%mod*(i+2)%mod) % mod;
    }
    printf("%lld\n",ans);
}