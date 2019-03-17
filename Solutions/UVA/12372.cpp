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

int N, arr[3], x = 1;
int main()
{
	bool isgood;
	scanf("%d", &N);
	while(x <= N)
	{
		isgood = true;
		REP(i, 0, 3)
		{
			scanf("%d", &arr[i]);
			if (arr[i] > 20) isgood = false;
		}
		isgood ? printf("Case %d: good\n", x) : printf("Case %d: bad\n", x);
		x++;
	}
    return 0;
}
