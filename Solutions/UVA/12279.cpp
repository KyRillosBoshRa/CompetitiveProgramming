#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const int NPOS = -1;

int N, x, ans, Case = 1;
int main()
{
	scanf("%d", &N);
	while(N)
	{
		ans = 0;
		while(N--)
		{
			scanf("%d", &x);
			!x ? ans-- : ans++;
		}
		printf("Case %d: %d\n", Case, ans);
		++Case;
		scanf("%d", &N);
	}
    return 0;
}
