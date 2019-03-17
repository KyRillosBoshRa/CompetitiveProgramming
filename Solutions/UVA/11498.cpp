#include <bits/stdc++.h>
using namespace std;
int x, n, m, k, l;
int main()
{
//	freopen("input.txt", "r", stdin);
    while(true)
    {
    	scanf("%d", &x);
    	if (!x) exit(0);
    	scanf("%d%d", &n, &m);
    	while(x--)
    	{
    		scanf("%d%d", &k, &l);
    		if (k == n || l == m)
    			printf("divisa\n");
    		else if (k > n && l > m)
    			printf("NE\n");
    		else if (k > n && l < m)
    			printf("SE\n");
    		else if (k < n && l > m)
    			printf("NO\n");
    		else
    			printf("SO\n");
    	}
    }
    return 0;
}
