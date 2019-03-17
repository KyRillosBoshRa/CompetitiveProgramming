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

int N, x;
char s[10];
int main()
{
	scanf("%d", &N);
	while(N--)
	{
		x = 0;
		scanf("%s", s);
		if (strlen(s) > 3)
			printf("3\n");
		else
		{
			if (s[0] == 'o') ++x;
			if (s[1] == 'n') ++x;
			if (s[2] == 'e') ++x;
			x >= 2 ? printf("1\n") : printf("2\n");
		}
	}
    return 0;
}
