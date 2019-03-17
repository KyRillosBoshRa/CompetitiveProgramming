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
typedef pair<int, int>         ii;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;

int n;
string s;
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    while(n--)
    {
        cin >> s;
        if(s == "78" || s == "1" || s == "4")
            cout << '+' << endl;
        else if(s[s.size()-1] == '5' && s[s.size()-2] == '3')
            cout << '-' << endl;
        else if(s[0] == '9' && s[s.size()-1] == '4')
            cout << '*' << endl;
        else
            cout << '?' << endl;
    }
	return 0;
}
