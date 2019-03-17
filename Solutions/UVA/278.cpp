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

int N, m, n, ans;
char ch;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin >> N;
	while(N--)
	{
		cin >> ch >> m >> n;
		if (ch == 'r' || ch == 'Q') ans = min(n, m);
		else if (ch == 'K') ans = ((max(n, m)+1)/2) * ((min(n, m)+1)/2);
		else if (ch == 'k') ans = (n*m+1)/2;
		cout << ans << endl;
	}
	return 0;
}
