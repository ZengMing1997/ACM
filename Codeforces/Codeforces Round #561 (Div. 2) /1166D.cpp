#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        //cout<<(1LL<<50)<<endl;
        LL a , b , m;
        scanf("%lld%lld%lld",&a,&b,&m);
        if(a == b)
        {
            printf("1 %lld\n",a);
            continue;
        }
        LL pos = -1;
        for(LL i = 0 ; i < 50 ; i++)
        {
            if((1LL<<i) *(a+1) > b) break;
            if((1LL<<i) *(a+1) <= b && (1LL<<i) * (a+m) >= b)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1) puts("-1");
        else 
        {
            cout<<pos+2<<" "<<a<<" ";
            for(LL i = pos ; i >= 1 ; i--)
            {
                cout<<(((b>>(i-1))+1)>>1)<<" ";
            }
            cout<<b<<endl;
        }
    }
}