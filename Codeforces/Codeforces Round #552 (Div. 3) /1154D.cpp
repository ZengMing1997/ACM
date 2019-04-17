#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int s[maxn];
int main()
{
    int n , b , a;
    scanf("%d%d%d",&n,&b,&a);
    int p = a;
    for(int i = 0 ; i < n ; i++) scanf("%d",&s[i]);
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i])
        {
            if(a == p) a--;
            else if(b) b-- , a++;
            else a--;
        }
        else 
        {
            if(a) a--;
            else if(b) b--;
        }
        if(b == 0 && a == 0)
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("%d\n",n);
}