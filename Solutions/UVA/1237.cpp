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
const int NPOS = -1;

const int MAX = 10001;
string an = "UNDETERMINED", ans;
vector<pair<string, pair<int, int> > > br(MAX);
int n, x, xx, y;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> n;
    while(n--)
    {
        cin >> x;
        REP(i, 0, x)
            cin >> br[i].first >> br[i].second.first >> br[i].second.second;
        cin >> xx;
        while(xx--)
        {
            ans = an;
            cin >> y;
            REP(i, 0, x)
                if (y >= br[i].second.first && y <= br[i].second.second)
                    if(ans == an) ans = br[i].first;
                    else {ans = an;break;}
            cout << ans << endl;
        }
        if (n != 0) cout << endl;
    }
    return 0;
}
