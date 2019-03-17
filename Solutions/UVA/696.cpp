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

int n, m, ans, MN, MX;
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> n >> m;
	while(n != 0 || m != 0)
	{
	    MX = max(n, m); MN = min(n, m);
	    if(n >= 3 && m >= 3) ans = (n*m+1)/2;
        else if(MN == 0) ans = 0;
        else if(MN == 1) ans = MX;
        else if(MN == 2){
            if(MX%4 == 0 || MX%4 == 3) ans = (MX+1)/2*2;
            else ans = (MX+2)/2*2;
        }
        cout << ans << " knights may be placed on a " << n  << " row " << m << " column board." << endl;
		cin >> n >> m;
	}
	return 0;
}
