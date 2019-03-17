#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const int NPOS = -1;

string s;
int x;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	while(s != "*")
	{
		cout << "Case " << ++x << ": ";
		cout << (s == "Hajj" ? "Hajj-e-Akbar": "Hajj-e-Asghar") << endl;
		cin >> s;
	}
    return 0;
}
