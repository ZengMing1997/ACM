#include <bits/stdc++.h>
using namespace std;
int vis[(1<<18)];
vector<int>V;
int main()
{
  int n , x;
  scanf("%d%d",&n,&x);
  V.push_back(0);
  vis[0] = 1;
  for(int i = 1 ; i < (1<<n) ; i++)
  {
    if(vis[i^x]) continue;
    V.push_back(i);
    vis[i] = 1;
  }
  cout<<V.size() - 1<<endl;
  for(int i = 1 ; i < V.size(); i++)cout<<(V[i]^V[i-1])<<" ";puts("");
}
