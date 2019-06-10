#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
priority_queue<int, vector<int>, greater<int> >Q;
pair<int,int>P[maxn];
int main()
{
  int n , m;
  scanf("%d%d",&n,&m);
  for(int i = 0 ; i < n ; i++)
  {
    int t;scanf("%d",&t);
    Q.push(t);
  }
  for(int i = 0 ; i < m ; i++)
  {
    int k , t;scanf("%d%d",&P[i].first,&P[i].second);
  }
  sort(P,P+m,[](pair<int,int>A,pair<int,int>B)
  {
    return A.second > B.second;
  });
  int flag = 0;
  for(int i = 0 ; i < m ; i++)
  {
    while(P[i].first--)
    {
      if(P[i].second > Q.top()) Q.pop() , Q.push(P[i].second);
      else {flag = 1;break;}
    }
    if(flag) break;
  }
  LL ans = 0;
  while(!Q.empty())
  {
    ans += Q.top();
    Q.pop();
  }
  printf("%lld\n",ans);
}