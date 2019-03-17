#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define all(v)				   ((v).begin()), ((v).end())
#define toint(x)               (x - '0')

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;

const int MAX = 101;
int n, m, a[MAX][MAX], field;
string str[MAX];
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> n >> m;
	while(n != 0 && m != 0)
    {
        REP(i, 0, n)
            cin >> str[i];
        REP(i, 0, n)
            REP(j, 0, m)
                if(str[i][j] == '*')
                    a[i][j] = -1;
        REP(i, 0, n)
            REP(j, 0, m)
            {
                if(str[i][j] == '*')
                {
                    if (i-1 >= 0 && a[i-1][j] != -1) a[i-1][j] += 1;
                    if (i+1 < n && a[i+1][j] != -1) a[i+1][j] += 1;
                    if (j-1 >= 0 && a[i][j-1] != -1) a[i][j-1] += 1;
                    if (j+1 < m && a[i][j+1] != -1) a[i][j+1] += 1;

                    if (i-1 >= 0 && j-1 >= 0 && a[i-1][j-1] != -1) a[i-1][j-1] += 1;
                    if (i+1 < n && j-1 >= 0 && a[i+1][j-1] != -1) a[i+1][j-1] += 1;
                    if (i-1 >= 0 && j+1 < m && a[i-1][j+1] != -1) a[i-1][j+1] += 1;
                    if (i+1 < n && j+1 < m && a[i+1][j+1] != -1) a[i+1][j+1] += 1;
                }
            }
        cout << "Field #" << ++field << ":" << endl;
        REP(i, 0, n)
        {
            REP(j, 0, m)
                if (a[i][j] == -1) cout << '*';
                else cout << a[i][j];
            cout << endl;
        }
        REP(i, 0, n)
            REP(j, 0, m)
                a[i][j] = 0;
        cin >> n >> m;
        if (n != 0 && m != 0) cout << endl;
    }
	return 0;
}
