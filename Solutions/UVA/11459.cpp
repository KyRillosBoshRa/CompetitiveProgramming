#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define ALL(v)				   ((v).begin()), ((v).end())
#define toInt(x)               (x - '0')
#define UNIQUE(c)              (c).resize(unique(ALL(c)) - (c).begin())

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;

const int MAX = 1000005;
int N, a, b, c, x, y, z, ii;
int scut[105], player[MAX];
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> N;
	while(N--)
    {
        cin >> a >> b >> c;
        REP(i, 0, 105)
            scut[i] = 0;
        REP(i, 0, a+1)
            player[i] = 1;
        REP(i, 0, b)
        {
            cin >> x >> y;
            scut[x] = y;
        }
        ii = 1;
        while(c--)
        {
            if (ii > a) ii -= a;
            cin >> z;
            player[ii] += z;
            if(player[ii] < 100 && scut[player[ii]] != 0) player[ii] = scut[player[ii]];
            if(player[ii] >= 100) {player[ii] = 100; break;}
            ++ii;
        }
        REP(i, 0, c) cin >> z;
        REP(i, 1, a+1)
            cout << "Position of player " << i << " is " << player[i] << '.' << endl;
    }
	return 0;
}
