#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn] ,vis[maxn];
vector<int>V;
int main()
{
    int n;
    scanf("%d",&n);
    int NUM = 0 , MAX = 0 , pos = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d",&a[i]);
        vis[a[i]] ++;
        if(MAX < vis[a[i]])
        {
            MAX = vis[a[i]];
            NUM = a[i];
            pos = i;
        }
    }
    printf("%d\n",n-MAX);
    if(MAX == n) return 0;
    for(int i = pos ; i + 1 <= n ; i++)
    {
        if(a[i] > a[i+1]) printf("1 %d %d\n",i+1,i) , a[i+1] = a[i];
        else if(a[i] < a[i+1]) printf("2 %d %d\n",i+1,i) , a[i+1] = a[i];
    }
    for(int i = pos ;i >= 2 ; i--)
    {
        if(a[i] > a[i-1]) printf("1 %d %d\n",i-1,i) , a[i-1] = a[i];
        else if(a[i] < a[i-1]) printf("2 %d %d\n",i-1,i) , a[i-1] = a[i];
    }
    return 0;
}