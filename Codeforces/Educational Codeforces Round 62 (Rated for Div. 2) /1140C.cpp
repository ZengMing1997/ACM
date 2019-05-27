#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
struct node
{
    int x,y;
    friend bool operator < (const node a , const node b)
    {
        return a.y > b.y;
    }
}edg[maxn];
int main()
{
    int n,m;
    priority_queue<int, vector<int>, greater<int> > Q;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ; i++) scanf("%d%d",&edg[i].x, &edg[i].y);
    sort(edg,edg+n);
    long long sum = 0 , ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum += edg[i].x;
        Q.push(edg[i].x);
        if(Q.size() > m) sum -= Q.top(),Q.pop();
        ans = max(ans,sum*edg[i].y);
    }
    cout<<ans<<endl;

}