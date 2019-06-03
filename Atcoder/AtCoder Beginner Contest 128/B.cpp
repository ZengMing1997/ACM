#include <bits/stdc++.h>
using namespace std;
struct node
{
  int pos;
  string name;
  int score;
  node (int pos,string name,int score):pos(pos),name(name),score(score){}
  friend bool operator < (const node a, const node b)
  {
    if(a.name == b.name) return a.score > b.score;
    else return a.name < b.name;
  }
};
int main()
{
  int n;
  scanf("%d",&n);
  vector<node>V;
  pair<string,int>P[n+1];
  string str;
  int score;
  for(int i = 1 ; i <= n ; i++)
  {
    cin>>str>>score;
    V.push_back(node(i,str,score));
  }
  sort(V.begin(),V.end());
  for(int i = 0 ; i < V.size() ; i++) cout<<V[i].pos<<endl;

}