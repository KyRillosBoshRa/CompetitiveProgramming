#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i >= int(b); --i)
#define ALL(v)				   ((v).begin()), ((v).end())
#define toInt(x)               (x - '0')
#define UNIQUE(c)              (c).resize(unique(ALL(c)) - (c).begin())

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;

const int MAX = 100001;
int x, y;
vi vec;
void bulid()
{
    int i = 1;
    while(i*i < MAX)
    {
        vec.pb(i*i);
        ++i;
    }
}
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	bulid();
	cin >> x >> y;
    while(x != 0 || y != 0)
    {
        cout << upper_bound(ALL(vec), y) - lower_bound(ALL(vec), x) << endl;
        cin >> x >> y;
    }
    return 0;
}
