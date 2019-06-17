#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];
map<int,int>M1,M2;
vector<pair<int,int> >P1 , P2;
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++)
  {
    scanf("%d",&a[i]);
  }
  int t1 = 0 , t2 = 0;
  for(int i = 0 ; i < n ; i += 2)
  {
    M1[a[i]]++;
  }
  for(int i = 1 ; i < n ; i += 2)
  {
    M2[a[i]]++;
  }
  int MAX1 = 0 , MAX2 = 0 , p1 , p2 ;
  for(auto i : M1)
  {
    P1.push_back(make_pair(i.second,i.first));
  }
  P1.push_back(make_pair(0,0));
  P2.push_back(make_pair(0,0));
  for(auto i : M2)
  {
    P2.push_back(make_pair(i.second,i.first));
  }
  sort(P1.begin(),P1.end(),[](pair<int,int>A,pair<int,int>B)
  {
    return A.first > B.first;
  });
  sort(P2.begin(),P2.end(),[](pair<int,int>A,pair<int,int>B)
  {
    return A.first > B.first;
  });
  if(P1[0].second != P2[0].second)
  {
    cout<<n - P1[0].first - P2[0].first<<endl;
  }
  else 
  {
    cout<<min(n - P1[0].first - P2[1].first , n -  P1[1].first - P2[0].first)<<endl;
  }
}