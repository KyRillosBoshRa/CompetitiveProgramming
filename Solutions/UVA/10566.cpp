#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i >= int(b); --i)
#define ALL(v)				   ((v).begin()), ((v).end())
#define toInt(x)               (x - '0')
#define UNIQUE(c)              (c).resize(unique(ALL(c)) - (c).begin())
#define F                      first
#define S                      second

typedef long long              ll;
typedef vector <int>           vi;
typedef pair<int, int>         ii;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int MAX = 1000005;

double x, y, c;
string s;
double solve(double mid)
{
    double A = sqrt((x*x) - (mid*mid));
    double B = sqrt((y*y) - (mid*mid));
    return ((A*B)/(A+B));
}
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	while(cin >> x >> y >> c)
    {
        int cnt = 150;
        double lo = 0, hi = min(x, y), mid;
        while(cnt--)
        {
            mid = (lo+hi)/2;
            if(solve(mid) <= c) hi = mid;
            else lo = mid;
        }
        cout << fixed << setprecision(3) << lo << endl;
    }
    return 0;
}
