#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define ALL(x)                 (x).begin(), (x).end()
#define toint(x)               (x - '0')

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;

const int MAX = 53;
int n, y, x, X, z, test;
string arr[MAX];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin >> n;
	while(n--)
	{
		REP(i, 1, MAX)
			cin >> arr[i];
		x = X = y =0; z = 3;
		while(z--)
		{
		    x = X+1;
			if(isdigit(arr[x][0])) x = toint(arr[x][0]);
			else x = 10;
			y += x;
			X += 11 - x;
		}
		cout << "Case " << ++test << ": " << arr[(y+X)%MAX] << endl;
	}
	return 0;
}
