#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
int n, ans, f[N][2];
char s[N];
int main()
{
  scanf("%s", s + 1);
  n = strlen(s + 1);
  f[0][1] = 1;
  for (int i = 1; i <= n; i++)
    if (s[i] == '1')
      f[i][0] = (3ll * f[i - 1][0] + f[i - 1][1]) % mod, f[i][1] = 2ll * f[i - 1][1] % mod;
    else
      f[i][0] = 3ll * f[i - 1][0] % mod, f[i][1] = f[i - 1][1];
  ans = (f[n][0] + f[n][1]) % mod;
  printf("%d", ans);
}