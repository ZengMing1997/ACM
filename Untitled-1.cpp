
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+8;
#define int long long
int a[maxn] , b[maxn];
signed main()
{
	int t , n , k ;
	scanf("%lld" , &t);
	while(t--)
	{
		int x;
		int p = 1,q = 1 , ans = 0;
		scanf("%lld %lld" , &n , &k);
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%lld" ,&x);
			if(x < 0) 
			{
				a[p] = -x;
				p++;
			}
			if(x > 0) 
			{
				b[q] = x;
				q++;
			}
		}
	//	printf("p = %d q = %d\n" , p , q);
		sort(a+1 , a+p);
		sort(b+1 , b+q);
		if(a[p-1] <= b[q-1] && (a[p-1]!=0 && b[q-1]!= 0))
		{
			int x = p-1,y = q-1;
			while(x>0)
			{
				ans += a[x];
				x -= k;
			}
			while(y>0)
			{
				y -= k;
				ans += b[y];
			}
			ans = ans *2 + b[q-1];
		}
		else if(a[p-1] > b[q-1] && ( a[p-1]!=0 && b[q-1]!= 0))
		{
			int x = p-1,y = q-1;
			while(x > 0)
			{
				x -= k;
				ans += a[x];
			}
			while(y>0)
			{
				ans += b[y];
				y -= k; 
			}
			ans = ans *2 + a[p-1];
		}
		else if(a[p-1]==0 && b[q-1]!= 0)
		{
			int x = p-1,y = q-1;
			while(y>0)
			{
				ans += b[y];
				y -= k;
			}
			ans = ans *2;
		}
		else if(a[p-1]!=0 && b[q-1]== 0)
		{
			int x = p-1,y = q-1;
			while(x>0)
			{
				ans += a[x];
				x -= k;
			}
			ans = ans *2;
		}
		printf("%lld\n" , ans);
	 } 
	return 0;
}
/*
2
5 3
-1 -2 3 -4 -5
6 3
1 0 -2 -1 1 2
*/
