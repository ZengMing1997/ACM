#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int s[maxn],t[maxn] , NUM[maxn];
string a,b;
int main()
{
    int n;
    scanf("%d",&n);
    cin>>a>>b;
    int jw = 0;
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        int x = b[i] - 'a';
        int y = a[i] - 'a';
        if(x - y < 0)
        {
            x += 26;
            b[i-1] --;
        }
        if((x - y)%2 == 0) NUM[i] = (x-y)/2;
        else 
        {
            NUM[i] = (x-y)/2;
            NUM[i+1] += 13;
        }
    }
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        int x = a[i] - 'a';
        NUM[i-1] += (x+NUM[i])/26;
        NUM[i] = (x+NUM[i])%26;
    }
    for(int i = 0 ; i < n ; i++) printf("%c",NUM[i]+'a');
}