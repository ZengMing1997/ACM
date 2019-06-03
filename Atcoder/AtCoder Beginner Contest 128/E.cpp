#include <bits/stdc++.h>
using namespace std;
struct node
{
  int s,e,co;
  node (int s,int e,int co) : s(s) , e(e) , co(co) {}
  friend bool operator < (const node a,const node b)
  {
    if(a.s == b.co) return a.s < b.s;
    return a.co < b.co;
  }
};
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<node>V(n);
  for(int i = 0 ; i < n ; i++)
  {
    int s,e,co;
    scanf("%d%d%d",&s,&e,&co);
    V.push_back(node(s,e,co));
  }
  sort(V.begin(),V.end());
}