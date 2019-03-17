#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define ALL(x)                 x.begin(), x.end()

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const int NPOS = -1;

const int MAX = 101;
int n, z, a;
string s[16] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"}
, name[MAX];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	REP(i, 0, n)
		cin >> name[i];
	bool alldone = 0;
	while(!alldone || a != 16)
	{
		a == 16 ? a=0 : a;
		cout << name[z++] << ": " << s[a++] << endl;
		z == n ? alldone=1,z=0 : z;
	}
    return 0;
}
