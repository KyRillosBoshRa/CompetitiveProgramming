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

string s, str;
bool bla; int n;
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    getline(cin, s);
	while(true)
    {
        bla = true;
        REP(i, 0, s.size())
            if(isalpha(s[i]))
            {
                s[i] = tolower(s[i]);
                str += s[i];
            }
        n = str.size();
        REP(i, 0, n/2)
            if(str[i] != str[n-1-i])
                {bla = false; break;}
        str.clear();
        cout << (bla ? "You won't be eaten!" : "Uh oh..") << endl;
        getline(cin, s);
        if (cin.peek() == EOF) break;
    }
	return 0;
}
