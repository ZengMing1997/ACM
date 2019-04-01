#include <bits/stdc++.h>
const int mod = 1e9+7;
const int maxn = 2002;
using namespace std;
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
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    long long ans = 0 ;
    if(k == 1 || k > n) {cout<<qpow(m,n)<<endl; return 0;}
    if(k == n)
    {
        //cout<<qpow(m,n/2)<<endl;
        if(k&1) cout<<(m*qpow(m,n/2))%mod<<endl;
        else cout<<qpow(m,n/2)<<endl;
        return 0;
    }
    if(k & 1)
    {
        ans = (ans + m)%mod;
        ans = (ans + m * (m-1)) % mod;
        cout<<ans<<endl;
    }
    else cout<<m<<endl;
}