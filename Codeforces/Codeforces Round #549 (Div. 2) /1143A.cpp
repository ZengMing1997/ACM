#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int a[maxn];
int main()
{
    int n , x = 0 , y = 0;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] == 0) x++;
        else y++;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == 0) x--;
        else y--;
        if(x == 0 || y == 0) {printf("%d",i+1);return 0;}
    }
}