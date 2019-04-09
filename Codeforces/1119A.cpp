#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int a[maxn];
int main()
{
    int n , ans = 0;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != a[n-1]) {ans = n-i-1;break;}
    }
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        if(a[0] != a[i]) {ans = max(ans,i);break;}
    }
    cout<<ans<<endl;
}