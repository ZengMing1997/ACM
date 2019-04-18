#include <bits/stdc++.h>
using namespace std;
vector<int>J,O;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        int t;scanf("%d",&t);
        if(t&1) J.push_back(t);
        else O.push_back(t);
    }
    sort(J.begin(),J.end(),[](int a,int b){return a > b;});
    sort(O.begin(),O.end(),[](int a,int b){return a > b;});
    int ans = 0;
    for(int i = min(J.size(),O.size()) + 1; i < max(J.size(),O.size()) ; i++)
    {
        if(i > J.size()) ans += O[i];
        else ans += J[i];
    }
    cout<<ans<<endl;
}