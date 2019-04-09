#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
int a[maxn] , sum[maxn];
int n , h;
int check(int pos)
{
    vector<int>V;
    for(int i = 0 ; i < pos ; i++) V.push_back(a[i]);
    long long h1 = 0;
    sort(V.begin() , V.end(),[](int a,int b){return a > b;});
    for(int i = 0 ; i < V.size() ; i = i + 2) h1 += V[i];
    return h1 <= h;
}
int main()
{
    
    scanf("%d%d",&n,&h);
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    int l = 0, r = n + 1;
    while(l < r)
    {
        int m = (l+r)/2;
        if(check(m)) l = m + 1;
        else r = m;
    }
    cout<< l - 1 <<endl;
}