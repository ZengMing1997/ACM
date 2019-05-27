#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int n;
    scanf("%d",&n);
    cin>>a;
    string b = a;
    int x[10];
    for(int i = 0 ; i < 10 ; i++)
    {
        x[i] += i;
    }
    sort(b.begin(),b.end());
    if(b == a) {puts("NO");return 0;}
    puts("YES");
    for(int i = 0 ; i + 1< a.size() ; i++)
    {
        if(a[i] > a[i+1])
        {
            printf("%d %d\n",i+1,i+2);
            return 0;
        }
    }
}