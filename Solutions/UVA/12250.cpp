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

int x;
string s;
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> s;
	while(s != "#")
	{
		cout << "Case " << ++x << ": ";
		if(s == "HELLO") cout << "ENGLISH" << endl;
		else if(s == "HOLA") cout << "SPANISH" << endl;
		else if(s == "HALLO") cout << "GERMAN" << endl;
		else if(s == "BONJOUR") cout << "FRENCH" << endl;
		else if(s == "CIAO") cout << "ITALIAN" << endl;
		else if(s == "ZDRAVSTVUJTE") cout << "RUSSIAN" << endl;
		else cout << "UNKNOWN" << endl;
		cin >> s;
	}
    return 0;
}