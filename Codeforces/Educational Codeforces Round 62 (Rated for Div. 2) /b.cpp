#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
int a[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;
        string s;
        scanf("%d",&n);
        cin>>s;
        int l = 0 , r = 0;
        for(int i = 0 ; i < s.size();i++)  if(s[i] == '<') r = i;
        for(int i = s.size() - 1 ; i >= 0 ; i --) if(s[i] == '>') l = i;
        cout<<min(l , int(s.size()) - r - 1)<<endl;
    }
}