#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int bin[maxn];
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
	bin[0] = 1;
	long double ans = 0;
	for(int i = 1 ; i <= 30 ; i++) bin[i] = bin[i-1] * 2;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 28 ; j >= 0 ; j--)
		{
			if(1LL * i * bin[j] < k)
			{
				ans += (long double) 1 / (bin[j+1]);
				break;
			}
		}
	}
	if(n >= k) ans += ((long double)n - (long double )k + (long double)1);
	printf("%.10Lf\n",ans / (long double)n - 1e-10);
 
}