#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
int a[maxn];
int main()
{
    int n , ans = 0 ,pos = 0;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
    {
        int t;scanf("%d",&t);
        pos = max(t,pos);
        if(i == pos) ans++;
    }
    cout<<ans<<endl;
}