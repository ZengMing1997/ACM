#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int vis[maxn] , a[maxn];
vector<int>A,B;
int main()
{
    int n , MAX = 0;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
        MAX = max(MAX,a[i]);
        vis[a[i]]++;
        if(vis[a[i]] >= 3)
        {
            puts("NO");
            return 0;
        }
    }
    sort(a,a+n);
    puts("YES");
    for(int i = 0 ; i < n ; i++)
    {
        if(vis[a[i]] >= 2)
        {
            A.push_back(a[i]);
            vis[a[i]] --;
        }
    }
    for(int i = n - 1 ;i >= 0 ; i--)
    {
        if(vis[a[i]] == 1)
        {
            B.push_back(a[i]);
            vis[a[i]]--;
        }
    }
    printf("%d\n",A.size());
    for(auto i : A) printf("%d ",i);puts("");
    printf("%d\n",B.size());
    for(auto i : B) printf("%d ",i);puts("");
}