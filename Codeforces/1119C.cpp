#include <bits/stdc++.h>
using namespace std;
const int maxn = 555;
int a[maxn][maxn] ,b[maxn][maxn];
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++) scanf("%d",&a[i][j]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++) scanf("%d",&b[i][j]);
    }
}