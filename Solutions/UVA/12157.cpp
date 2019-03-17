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

int N, X, y, Case;
ll mile, juice;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	while(N--)
	{
		cin >> X;
		mile = juice = 0;
		while(X--)
		{
			cin >> y;
			++y;
			mile  += ceil(y / 30.0)*10;
			juice += ceil(y / 60.0)*15;
		}
		if (mile < juice)
			cout << "Case " << ++Case << ": " << "Mile " << mile << endl;
		else if (mile == juice)
			cout << "Case " << ++Case << ": " << "Mile Juice " << mile << endl;
		else
			cout << "Case " << ++Case << ": " << "Juice " << juice << endl;
	}
    return 0;
}
