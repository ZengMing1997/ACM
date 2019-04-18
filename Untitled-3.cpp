#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n;
char s[maxn],t[maxn];
int ans[maxn];
int main()
{
    int i;
    int x,y;
    while(cin>>n)
    {
        getchar();
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        gets(s);
        gets(t);
        for(i=n-1;i>=0;i--)//低位到高位模拟减法和除法 
        {
            x = t[i] - 'a';
            y = s[i] - 'a';
            if(x - y < 0)//当前位不够减就借位 
            {
                t[i-1]--;
                x += 26;//注意借来的是十进制下的26 
            }
            if((x-y)%2 == 0)//模拟除法 
            ans[i] = (x-y)/2;
            else//该位是奇数
            {
                ans[i] = (x-y)/2;
                ans[i+1] += 13;//给后一位13（即这一位除2最后有0.5，就等于26进制下的13）
                                //这个过程可能会导致后一位超出26，下面再模拟一下加法取余即可  
            }
        }
        for(i=n-1;i>=0;i--)//低位到高位模拟加法 
        {
            x = s[i] - 'a';
            ans[i-1] += (x+ans[i])/26;//高位进位 
            ans[i] = (x+ans[i])%26;//低位取余 
        }
        for(i=0;i<n;i++)
        cout<<char(ans[i]+'a');
        cout<<endl;
    }
    return 0;
}