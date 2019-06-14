#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
void judge(ll m,ll x)
{
    if(!m)return;
    if(n / m == x && n % m == x) ans += m;
}
int main()
{
    cout<<(1^2)<<endl;
    cin>>n;
    for(ll i = 1;i * i <= n ; i++)
    if(n % i == 0)
    {
        judge(i - 1 , n / i);
        if(i * i < n)judge( n / i - 1 , i);
    }
    cout<<ans<<endl;
}