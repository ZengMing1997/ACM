#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main()
{
    int n;
    scanf("%d",&n);
    int m = n*n-n+1;
    int k = 1;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n - 1 ; j++) printf("%d ",k++);
        printf("%d\n",m++);
    }
}