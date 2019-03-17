#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define ALL(x)                 (x).begin(), (x).end()

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;

int n, x, y, mxy, test;
double mxp, p;
string s, ans;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin >> n >> x; cin.ignore();
	while(n != 0 || x != 0)
	{
		REP(i, 0, n)
			cin.ignore(1000, '\n');
		mxy = 0; mxp = 0;
		REP(i, 0, x)
		{
			getline(cin, s);
			cin >> p >> y; cin.ignore();
			if (y > mxy){mxy = y; mxp = p; ans = s;}
			else if (y == mxy)
				if(p < mxp){mxy = y; mxp = p; ans = s;}
			REP(j, 0, y)
				cin.ignore(1000, '\n');
		}
		cout << "RFP #" << ++test << endl << ans << endl;
		cin >> n >> x; cin.ignore();
		if(n != 0 || x != 0) cout << endl;
	}
	return 0;
}
