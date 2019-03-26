#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n ,m;
    scanf("%d%d",&n,&m);
    int pos = 0 , ans = 0;
    if(m > n - 1)
    {
        m = n - 1;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(pos < n - i)
        {
            ans += (m-pos)*i;
            pos = m;
        }
        pos--;
    }
    cout<<ans<<endl;
}