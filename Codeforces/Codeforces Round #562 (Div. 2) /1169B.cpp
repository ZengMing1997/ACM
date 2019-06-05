#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
pair<int,int>P[maxn];
int main() 
{
  int n , m , MAX1 = -1 , MAX2 = -1;
  scanf("%d%d",&n,&m);
  for(int i = 0 ; i < m ; i++)
  {
    scanf("%d%d",&P[i].first,&P[i].second);
  }
  vector<int>V = {P[0].first,P[0].second};
  for(int i : V)
  {
    vector<int>vis(n,0);
    int p = 0 ,MAX = 0;
    for(int j = 0 ; j < m ; j++)
    {
      if(P[j].first != i && P[j].second != i)
      {
        vis[P[j].first]++ , vis[P[j].second]++;p++;
        MAX = max(MAX,vis[P[j].first]);
        MAX = max(MAX,vis[P[j].second]);
      }
    }
    if(MAX == p)
    {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}