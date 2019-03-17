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

int x, y, z, mx;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> x;
	int num = 1;
	while(num <= x)
	{
		cin >> y;
		mx = 0;
		while(y--)
		{
			cin >> z;
			mx = max(z, mx);
		}
		cout << "Case " << num << ": " << mx << endl;
		++num;
	}
    return 0;
}
