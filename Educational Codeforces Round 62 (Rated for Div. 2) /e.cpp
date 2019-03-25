#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
const int mod = 998244353;
int dp[maxn][2];
long long qpow(long long a,int b)
{
    long long ans = 1;
    while(b)
    {
        if(b&1) ans = ans * a % mod;
        a = a* a % mod;
        b = b/2;
    }
    return ans;
}
vector<int>O,E;
int n,k;
long long solve(vector<int> &V)
{
    for(int i = 0 ; i < V.size() ; i ++)
    {
        if(V[i] == V[i+1] && V[i] != -1) return 0;
    }
    long long ans = 1;
    for(int i = 0 ; i < V.size() ; i++)
    {
        if(V[i] == -1)
        {
            int r = i , l = i;
            while(r+1 < V.size() && V[r+1] == -1) r++;
            if(r == V.size() - 1 && l == 0) {return k * qpow(k-1,V.size()-1) % mod;} // xxxx
            else if(l == 0 || r == V.size()-1) ans = ans * qpow(k-1,r-l+1) % mod;  // axxxx , xxxxa
            else if(V[l-1] == V[r+1]) ans = ans * dp[r-l+1][1] % mod;
            else if(V[l-1] != V[r+1]) ans = ans * dp[r-l+1][0] % mod;
            i = r;
        }
    }
    return ans;
}
int main()
{
    
    scanf("%d%d",&n,&k);
    for(int i = 0 ; i < n ; i++)
    {
        int t;scanf("%d",&t);
        if(i&1) O.push_back(t);
        else E.push_back(t);
    }
    dp[1][0] = k - 2;
    dp[1][1] = k - 1;
    for(int i = 2 ; i <= n ; i++)
    {
        dp[i][1] = (k-1) * dp[i-1][0] % mod;
        dp[i][0] = (dp[i-1][1] + (k-2) * dp[i-1][0]) % mod;
    }
    long long ans = solve(O) * solve(E) % mod;
    cout<<ans<<endl;
}