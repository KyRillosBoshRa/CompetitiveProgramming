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

int N;
int main()
{
	scanf("%d", &N);
	int x = 1;
	int arr[3];
	while(x <= N)
	{
	    REP(i, 0, 3)
			scanf("%d", &arr[i]);
		sort(arr, arr+3);
		printf("Case %d: %d\n", x, arr[1]);
		x++;
	}
    return 0;
}
