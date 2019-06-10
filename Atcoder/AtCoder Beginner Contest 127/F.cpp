#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
priority_queue<int>H; // 降序
priority_queue<int,vector<int> , greater<int> >L; // 升序
int main()
{
  int n;
  scanf("%d",&n);
  LL ans = 0;
  for(int i = 0 ; i < n ; i++)
  {
    int op;scanf("%d",&op);
    if(op == 1)
    {
      int a,b;scanf("%d%d",&a,&b);
      H.push(a);
      L.push(a);
      ans += b;
      if(H.top() > L.top())
      {
        int x = H.top();
        int y = L.top();
        H.pop() , L.pop();
        ans += abs(x-y);
        H.push(y), L.push(x);
      }
    }
    else 
    {
      cout<<H.top() <<" " << ans<<endl;
    }
  }
}