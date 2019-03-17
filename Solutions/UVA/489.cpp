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

int test, SIZE, win, lose;
string s1, s2, ans;
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> test;
	while(test != -1)
    {
        cin >> s2 >> s1;
        REP(i, 0, s1.size()-1)
            if(s1.find(s1[i], i+1) != string::npos) {s1.erase(s1.find(s1[i], i+1), 1); --i;}
        REP(i, 0, s2.size()-1)
            if(s2.find(s2[i], i+1) != string::npos) {s2.erase(s2.find(s2[i], i+1), 1); --i;}
        SIZE = s2.size(); lose = win = 0;
        REP(i, 0, s1.size())
        {
            if(s2.find(s1[i]) != string::npos) ++win;
            else ++lose;
            if(lose == 7 || win == SIZE) break;
        }
        if(win == SIZE) ans = "You win.";
        else if(lose == 7) ans = "You lose.";
        else ans = "You chickened out.";
        cout << "Round " << test << endl << ans << endl;
        cin >> test;
    }
	return 0;
}
