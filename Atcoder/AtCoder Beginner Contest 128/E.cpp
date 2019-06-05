#include <bits/stdc++.h>
using namespace std;
struct node
{
  int d,co,flag;
  node (int d, int co, int flag) : d(d) , co(co),flag(flag) {}
  friend bool operator < (const node a,const node b)
  {
    return a.d < b.d;
  }
};
multiset<int>M;
vector<node>V;
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 0 ; i < n ; i++)
  {
    int s,e,co;
    scanf("%d%d%d",&s,&e,&co);
    V.push_back(node(s-co,co,0));
    V.push_back(node(e-co,co,1));
  }
  sort(V.begin(),V.end());
  int k = 0;
  while(m--)
  {
    int q;
    scanf("%d",&q);
    while(k < V.size())
    {
      if(V[k].d <= q)
      {
        if(V[k].flag) M.erase(M.find(V[k].co));
        else M.insert(V[k].co); 
        k++;
      }
      else break;
     
    }
    int ans = - 1;
    if(M.size()) ans = *M.begin();
    cout<<ans<<endl;
  }
}