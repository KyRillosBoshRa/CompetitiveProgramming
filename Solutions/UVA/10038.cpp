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

const int MAX = 3001;
int n, arr[MAX], tw[MAX];
string ans;
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> n)
    {
    	tw[0] = -1;
    	ans = "Jolly";
        REP(i, 0, n)
	        cin >> arr[i];
	    REP(i, 0, n-1)
	    	tw[i] = abs(arr[i]-arr[i+1]);
	    sort(tw, tw+n-1);
	    REP(i, 0, n-2)
	    	if(tw[i+1] - tw[i] != 1) {ans = "Not jolly"; break;}
	    if(tw[0] != 1 && tw[0] != -1) ans = "Not jolly";
	    cout << ans << endl;
    }
	return 0;
}