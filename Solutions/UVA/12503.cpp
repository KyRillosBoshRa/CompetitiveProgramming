#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define ALL(x)                 x.begin(), x.end()

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const int NPOS = -1;

const int MAX = 101;
bitset<MAX> vb;
int n, x, y, c, co;
string s;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	while(n--)
	{
		c = co = 0;
		vb.reset();
		cin >> x;
		while(x--)
		{
			cin >> s;
			if (s == "RIGHT")
			{
				++c;
				vb.set(co);
			}
			else if (s == "LEFT")
				--c;
			else{
				cin >> s >> y;
				vb.test(y-1) ? vb.set(co),++c : --c;
			}
			++co;
		}
		cout << c << endl;
	}
    return 0;
}
