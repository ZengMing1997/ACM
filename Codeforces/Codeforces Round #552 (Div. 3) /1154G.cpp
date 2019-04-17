#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+10;
int vis[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    int X,Y;
    long long ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 0 ; i < n ; i++)
    {
        int t;scanf("%d",&t);
        if(vis[t] && ans > t)
        {
            ans = t;
            X = vis[t] ; Y = i+1;    
        }
        vis[t] = i+1;
    }
    for(int i = 1 ; i <= 1e7 ; i++)
    {
        vector<int>V;
        for(int j = i ; j <= 1e7 ; j += i)
        {
            if(vis[j]) V.push_back(j);
            if(V.size() == 2) break;
        }
        if(V.size() >= 2)
        {
            if(ans > 1LL*V[0] * V[1] / i)
            {
                X = vis[V[0]] , Y = vis[V[1]];
                ans = 1LL*V[0] * V[1] / i;
            }
        }
    }
    if(X > Y) swap(X,Y);
    printf("%d %d\n",X,Y);
}