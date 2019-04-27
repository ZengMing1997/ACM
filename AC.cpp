#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
int n, a[MAXN], ans[MAXN];
int mv(int x, int &sz)
{
    while (a[x] > 1) sz += a[x++];
    sz += a[x];
    return x;
}
int main()
{
	scanf("%d", &n);
    int MIN = MAXN, MAX = 0; 
	for (int i = 1; i <= n; i++) 
	{
		int x; scanf("%d", &x);
		a[x]++;
        MIN = min(MIN, x);
        MAX = max(MAX, x);
	}
    int sz = a[MIN];
    int s = MIN, e = mv(s + 1, sz), L = e, R;
    //cout << s << " " << e << endl;
    while (L <= MAX)
    {
        while (L <= MAX && a[L] == 0) L++;
        int tmp = a[L];
        R = mv(L + 1, tmp);
        //cout << L << " " << R << endl;
        if (tmp > sz) sz = tmp, s = L, e = R;
        L = R;
    }
	L = n / 2, R = n / 2;
	for (int i = s; i <= e; i++)
	{
		if (a[i]) a[i]--, ans[--L] = i;
		while (a[i]--) ans[R++] = i;
	}
	printf("%d\n", R - L);
	for (int i = L; i < R; i++) printf("%d ", ans[i]);
	return 0;
}
/*
7
4 3 5 1 2 2 1
*/