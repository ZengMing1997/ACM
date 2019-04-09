#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int vis[maxn];
int main()
{
    int n , a,b,d;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++) vis[i] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d%d",&a,&b);
        if(a == -1) {d = i;continue;}
        if(b == 0) vis[i] = 0 , vis[a] = 0;
    }
    int flag = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(vis[i] && i!= d)
        {
            printf("%d ",i);
            flag = 1;
        }
    }
    if(!flag) puts("-1");
}