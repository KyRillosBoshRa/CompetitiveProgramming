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

int king[3], pr[3], x, ans, Find[5];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	REP(i, 0, 3) cin >> pr[i];
    REP(i, 0, 2) cin >> king[i];
    REP(i, 0, 3) {Find[i] = pr[i]; Find[3] = king[0]; Find[4] = king[1];}
	while(pr[0])
	{
	    x = 0;
	    sort(pr, pr+3); sort(king, king+1); reverse(pr, pr+2);
        if(*(max_element(king, king+2)) > *(max_element(pr, pr+3))) {*(max_element(king, king+2)) = *(min_element(pr, pr+3)) = 0; ++x;}
        else REP(i, 0, 3) if(pr[i] > *(max_element(king, king+2))) {pr[i] = *(max_element(king, king+2)) = 0; break;}
        if(*(max_element(king, king+2)) > *(max_element(pr, pr+3))) {*(max_element(king, king+2)) = *(min_element(pr, pr+3)) = 0; ++x;}
        else REP(i, 0, 3) if(pr[i] > *(max_element(king, king+2))) {pr[i] = *(max_element(king, king+2)) = 0; break;}
        if(x < 1) cout << -1 << endl;
        else
        {
            if(x == 2) ans = 1;
            else ans = *(max_element(pr, pr+3));
            while(find(Find, Find+5, ans) != Find+5) {++ans; if (ans > 52) {ans = -1; break;}}
            cout << ans << endl;
        }
        REP(i, 0, 3) cin >> pr[i];
        REP(i, 0, 2) cin >> king[i];
        REP(i, 0, 3) {Find[i] = pr[i]; Find[3] = king[0]; Find[4] = king[1];}
	}
	return 0;
}
